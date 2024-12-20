#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int l, n;
    scanf("%d %d", &l, &n);
    vector < pair <int, int> > router(n);
    for (int i=0; i<n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        router[i].first = a-b;
        router[i].second= a+b;
        if (a-b < 0)
            router[i].first=0;
        if (a+b>l)
            router[i].second=l;
    }
    sort(router.begin(), router.end());
    priority_queue <int> consider;
    bool found=true;
    int end=0, count=0;
    for (int i=0; i<n; i++)
    {
        if (router[i].first > end)
        {
            if (consider.empty())
            {
                // printf("1\n");
                found=false;
                break;
            }
            else if (router[i].first > consider.top())
            {
                // printf("2 %d\n", consider.top());
                found=false;
                break;
            }
            else if (consider.top() < router[i].second)
            {
                // printf("3\n");
                count++;
                end=consider.top();
                while (!consider.empty())
                    consider.pop();
                consider.push(router[i].second);
            }
        }
        else
        {
            // printf("4\n");
            while (!consider.empty() && consider.top()<router[i].second)
            {
                consider.pop();
            }
            if (consider.empty())
                consider.push(router[i].second);
        }
        
    }
    if (end!=n)
    {
        // printf("5 %d\n", end);
        if (!consider.empty() && consider.top()==l)
        {
            count++;
        }
        else
            found=false;
    }
    if (found)
        printf("%d\n", count);
    else
        printf("-1\n");   
}