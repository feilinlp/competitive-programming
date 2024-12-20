#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        vector <int> s(n);
        for (int j=0; j<n; j++)
        {
            scanf("%d", &s[j]);
        }
        int l=-1, r=-1;
        for (int j=0; j<n; j++)
        {
            if (l==-1)
            {
                if (s[j]==j+1)
                {
                    printf("%d ", s[j]);
                }
                else
                    l=j;
            }
            else
            {
                if (s[j]==l+1)
                {
                    r=j;
                    break;
                }
            }
        }
        if (l!=-1)
        {
            for (int j=r; j>=l; j--)
            {
                printf("%d ", s[j]);
            }
            for (int j=r+1; j<n; j++)
            {
                printf("%d ", s[j]);
            }
        }
        printf("\n");
    }
}