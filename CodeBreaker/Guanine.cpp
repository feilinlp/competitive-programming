#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string s;
    char c;
    int x, pos=0, amt=0;
    deque <char> q, temp;

    while (pos<n)
    {
        cin>>s;
        if (s=="ADD_FRONT")
        {
            scanf(" %c", &c);
            q.push_front(c);
            amt++;
        }
        else if (s=="ADD_BACK")
        {
            scanf(" %c", &c);
            q.push_back(c);
            amt++;
        }
        else if (s=="QUERY")
        {
            scanf("%d", &x);
            for (int i=0; i<x; i++)
            {
                temp.push_back(q.front());
                q.pop_front();
            }
            printf("%c\n", q.front());
            for (int i=0; i<x; i++)
            {
                q.push_front(temp.back());
                temp.pop_back();
            }
        }
        else if (s=="SNIP_FRONT")  
        {
            scanf("%d", &x);
            for (int i=0; i<x+1; i++)
                q.pop_front();
            amt-=x+1;
        }
        else if (s=="SNIP_BACK")
        {
            scanf("%d", &x);
            for(int i=0; i<amt-x-1;i++)
                q.pop_back();
            amt=x+1;
        }
        pos++;
    }
}