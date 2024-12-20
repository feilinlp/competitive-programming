#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    deque <int> q;
    int x;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        if (n%2==0)
        {
            if (i%2==0)
                q.push_back(x);
            else
                q.push_front(x);
        }
        else
        {
            if (i%2==1)
                q.push_back(x);
            else
                q.push_front(x);
        }
    }

    for (int i=0; i<n; i++)
    {
        printf("%d", q.front());
        q.pop_front();
        if (i!=n-1)
            printf(" ");
        else
            printf("\n");
    }
}