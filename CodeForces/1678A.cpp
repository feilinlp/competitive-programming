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
        vector <int> num(101, 0);
        bool same = false, zero=false;
        for (int j=0; j<n; j++)
        {
            int x;
            scanf("%d", &x);
            num[x]++;
            if (x==0)
                zero=true;
            if (num[x]>1)
                same=true;
        }
        int ans=0;
        if (zero)
        {
            ans = 
        }
        else
        {
            for (int j=1; j<101; j++)
            {

            }
        }
    }
}