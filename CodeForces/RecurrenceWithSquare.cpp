#include <cstdio>
#include <vector>

using namespace std;

const int MOD=1e9+7;
int main()
{
    int n;
    long long k;
    scanf("%d %lld", &n, &k);
    vector < vector<int> > t(n+3, vector <int> (n+3, 0));
    vector <int> in(n+3);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &in[i]);
    }
    in[n]=1;
    in[n+1]=n;
    in[n+2]=n*n;
    for (int i=0; i<n-1; i++)
    {
        t[i][i+1]=1;
    }
    for (int i=n-1; i>=0; i--)
    {
        scanf("%d", &t[n-1][i]);
    }
    for (int i=n; i<n+3; i++)
    {
        scanf("%d", &t[n-1][i]);
    }
    t[n][n]=1;
    t[n+1][n]=1;
    t[n+1][n+1]=1;
    t[n+2][n]=1;
    t[n+2][n+1]=2;
    t[n+2][n+2]=1;
    //printf("%d\n", __LINE__);
    while (k>0)
    {
        if (k&1)
        {
            vector <int> temp(n+3, 0);
            for (int i=0; i<n+3; i++)
            {
                //printf("%d\n", __LINE__);
                for (int j=0; j<n+3; j++)
                {
                    temp[i]=((long long)t[i][j]*in[j]+temp[i])%MOD;
                }
            }
            in=temp;
        }
        vector < vector<int> > temp(n+3, vector <int> (n+3, 0));
        for (int i=0; i<n+3; i++)
        {
            //printf("%d\n", __LINE__);
            for (int j=0; j<n+3; j++)
            {
                for (int k=0; k<n+3; k++)
                {
                    temp[i][k]=(temp[i][k]+(long long)t[i][j]*t[j][k])%MOD;
                }
            }
        }
        //printf("%d\n", __LINE__);
        t=temp;
        k=k/2;
    }
    printf("%d\n", in[0]);
}