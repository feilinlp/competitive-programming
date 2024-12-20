#include <cstdio>

using namespace std;

int main()
{
    int n, l;
    scanf("%d %d", &n, &l);
    int one=l, two=l-1;
    bool ans = true;
    for (int i=0; i<n; i++)
    {
        // printf("%d %d\n", one, two);
        int x;
        scanf("%d", &x);
        if (x==1)
        {
            if (one<1)
                ans=false;
            one--;
            if (two>=2)
            {
                two-=2;
            }
            else if (two==1)
                two--;
        }
        else if (x==2)
        {
            if (two<1)
                ans=false;
            else if (two>=3)
                two-=3;
            else if (two==2)
                two-=2;
            else if (two==1)
                two--;
            one-=2;
        }
    }
    if (ans)
        printf("Yes\n");
    else
        printf("No\n");
}