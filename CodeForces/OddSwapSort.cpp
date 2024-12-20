#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n;
        scanf("%d", &n);
        vector <int> s(n);
        int o=-1, e=-1;
        bool ans=true;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &s[i]);
            if (s[i]%2==0)
            {
                if (s[i]>=o)
                    o=s[i];
                else
                    ans=false;
            }
            else
            {
                if (s[i]>=e)
                    e=s[i];
                else
                    ans=false;
            }
        }
        if (ans==true)
            printf("Yes\n");
        else
            printf("No\n");
    }
}