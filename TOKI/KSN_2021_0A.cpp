#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <char> s(n);
    for (int i=0; i<n; i++)
    {
        scanf(" %c", &s[i]);
        //printf("i = %d %c\n", i, s[i]);
    }
    //printf("%d\n", __LINE__);
    sort(s.begin(), s.end());

    vector <char> a(n);
    a[0]=s[0];
    int posa=1, diff=1, poss=1;
    while (posa<n && diff<n)
    {
        if (s[poss]==a[posa-1])
        {
            while ((s[diff]==a[posa-1] || s[diff]=='-') && diff<n)
            {
                //printf("HELLO");
                diff++;
            }
            if (diff<n)
            {
                a[posa]=s[diff];
                posa++;
                s[diff]='-';
                diff++;
            }
        }
        else
        {
            if (s[poss]!='-')
            {
                a[posa]=s[poss];
                s[poss]='-';
                posa++;
            }
            poss++;
        }
    }

    while (posa<n)
    {
        if (s[poss]!='-')
        {
            a[posa]=s[poss];
            s[poss]='-';
            posa++;
        }
        poss++;
    }

    posa=n-2;
    diff=n-2;
    for (int i=0; i<n; i++)
    {
        s[i]=a[i];
    }
    poss=n-2;
    
    while (posa>-1 && diff>-1)
    {
        if (s[poss]==a[posa+1])
        {
            while ((s[diff]==a[posa+1] || s[diff]=='-') && diff>-1)
            {
                //printf("HELLO");
                diff--;
            }
            if (diff>-1)
            {
                a[posa]=s[diff];
                posa--;
                s[diff]='-';
                diff--;
            }
        }
        else
        {
            if (s[poss]!='-')
            {
                a[posa]=s[poss];
                s[poss]='-';
                posa--;
            }
            poss--;
        }
        /*for (int i=0; i<n; i++)
        {
            printf("%c", a[i]);
            //printf("%d\n", __LINE__);
        }
        printf("\n");*/
    }

    while (posa>-1)
    {
       if (s[poss]!='-')
        {
            a[posa]=s[poss];
            s[poss]='-';
            posa--;
        }
        poss--;
    }


    /*int pos=1;
    while (pos<n-1)
    {
        if (s[pos]==s[pos-1] && s[pos]!=s[pos+1])
        {
            char temp=s[pos];
            s[pos]=s[pos+1];
            s[pos+1]=temp;
            pos=1;
            //printf("%d\n", __LINE__);
        }
        else
            pos++;
        //printf("%c %c\n", s[pos], s[pos+1]);
        //printf("%d\n", __LINE__);
    }

    pos=n-2;
    while (pos>0)
    {
        if (s[pos]==s[pos+1] && s[pos]!=s[pos-1])
        {
            char temp=s[pos];
            s[pos]=s[pos-1];
            s[pos-1]=temp;
            pos=n-2;
            //printf("%d\n", __LINE__);
        }
        else
            pos--;
        //printf("%c %c\n", s[pos], s[pos+1]);
        //printf("%d\n", __LINE__);
    }*/

    for (int i=0; i<n; i++)
    {
        printf("%c", a[i]);
        //printf("%d\n", __LINE__);
    }
    printf("\n");
}