#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    string c;
    cin>>c;
    deque <int> q;
    for (int i=0; i<n; i++)
    {
        q.push_back(i);
    }
    int i=0;
    while (c[i]!='.')
    {
        if (c[i]=='A')
        {
            q.push_back(q.front());
            q.pop_front();
        }
        else if (c[i]=='B')
        {
            int x=q.front();
            q.pop_front();
            q.push_back(q.front());
            q.pop_front();
            q.push_front(x);
        }
        i++;
    }
    for (int i=0; i<k-1; i++)
    {
        q.pop_front();
    }
    int a=q.front();
    q.pop_front();
    int b=q.front();
    q.pop_front();
    int d=q.front();
    printf("%d %d %d\n", a, b, d);
}