#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    while (x!=0)
    {
        stack <int> a, b;
        for (int i=0; i<x; i++)
        {
            int m;
            scanf("%d", &m);
            b.push(m);
        }
        for (int i=0; i<x; i++)
        {
            a.push(b.top());
            b.pop();
        }
        bool cek=true;
        int pos=1;
        while ((cek==true)&&(a.empty()==false))
        {
            if((a.empty()==false)&&(a.top()==pos))
            {
                pos++;
                a.pop();
            }
            else
            {
                if((b.empty()==false)&&(b.top()==pos))
                {
                    pos++;
                    b.pop();
                }
                else if ((b.empty())||((b.empty()==false)&&(b.top()>a.top())))
                {
                    b.push(a.top());
                    a.pop();
                }
                else
                    cek=false;
            }
            //printf("%d %d", a.top(), b.top());
        }
        
        if (cek==false)
            printf("no\n");
        else   
            printf("yes\n");
            
        scanf("%d", &x);    
    }
}