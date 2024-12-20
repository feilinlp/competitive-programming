#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int h, w;
    scanf("%d %d", &h, &w);
    vector < vector <int> > a(h, vector <int> (w));
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<w; j++)
            scanf("%d", &a[i][j]);
    }
    vector < vector < vector <int> > > dp(h, vector < vector <int> > (2, vector <int> (2, 1e9)));
    dp[0][0][0]=0;
    dp[0][0][1]=1;
    for (int i=1; i<h; i++)
    {
        for (int j=0; j<2; j++)
        {
            for (int k=0; k<2; k++)
            {
                for (int l=0; l<2; l++)
                {
                    vector <int> x(w, -1);
                    if (i>1) x=a[i-2];
                    vector <int> y = a[i-1];
                    vector <int> z = a[i];
                    for (int m=0; m<w; m++)
                    {
                        if (j) x[m]=1-x[m];
                        if (k) y[m]=1-y[m];
                        if (l) z[m]=1-z[m];
                    }
                    bool ok = true;
                    for (int m=0; m<w; m++)
                    {
                        if (x[m]!=y[m] && y[m] != z[m] && (m==0 || y[m]!=y[m-1]) && (m==w-1||y[m]!=y[m+1])) ok = false; //check for line i-1 so that it is non-isolated
                    }
                    if (i==h-1)
                    {
                        for (int m=0; m<w; m++)
                            if (z[m]!=y[m] && (m==0 || z[m] != z[m-1]) && (m==w-1||z[m]!=z[m+1])) ok = false; //check for line h-1, which is the ending, h-2 is considered above
                    }
                    if (ok)
                    {
                        dp[i][k][l]=min(dp[i][k][l], dp[i-1][j][k]+l); //i-1, i and i-2, i-1 + curr
                    }
                }
            }
        }
    }
    int ans=1e9;
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            ans=min(ans, dp[h-1][i][j]);
        }
    }
    if (ans!=1e9)
        printf("%d\n", ans);
    else
        printf("-1\n");
}