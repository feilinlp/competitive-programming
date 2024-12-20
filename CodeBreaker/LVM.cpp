#include <cstdio>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string s[n];
    int s2[n];
    for (int i=0; i<n; i++)
    {
        cin>>s[i];
        if (s[i]=="PUSH" || s[i]=="IFZERO")
            scanf("%d", &s2[i]);
        else
            s2[i]=0;
    }
    stack <int> l;
    int r=0, m=0;
    int scanned=-1;
    while (m<n)
    {
        if (s[m]=="PUSH")
        {
            l.push(s2[m]);
        }
        else if (s[m]=="STORE")
        {
            if (!l.empty())
            {
                r=l.top();
                l.pop();
            }
        }
        else if (s[m]=="LOAD")
        {
            l.push(r);
        }
        else if (s[m]=="PLUS")
        {
            int temp=l.top();
            l.pop();
            l.top()+=temp;
        }
        else if (s[m]=="TIMES")
        {
            int temp=l.top();
            l.pop();
            l.top()*=temp;
        }
        else if (s[m]=="IFZERO")
        {
            //printf("top:%d\n", l.top());
            if (!l.empty()&&l.top()==0)
                m=s2[m]-1;
            l.pop();
        }
        else if (s[m]=="DONE")
        {
            if (!l.empty())
                printf("%d\n", l.top());
            break;
        }
        m++;
    }
}