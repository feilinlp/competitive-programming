#include <iostream>
#define ll long long
#define MOD 1000000007

using namespace std;

int main()
{
    ll h, w;
    cin >> h >> w;
    char m[h][w];
    for (ll i=0; i<h; i++)
    {
        for (ll j=0; j<w; j++)
        {
            cin >> m[i][j];
        }
    }
    ll ans[h][w];
    bool found=false;
    for (ll j=0; j<w; j++)
    {
        if (m[0][j]=='.' && !found)
            ans[0][j]=1;
        else
        {
            found=true;
            ans[0][j]=0;
        }
    }
    found=false;
    for (ll i=0; i<h; i++)
    {
        if (m[i][0]=='.' && !found)
            ans[i][0]=1;
        else
        {
            found=true;
            ans[i][0]=0;
        }
    }
    for (ll i=1; i<h; i++)
    {
        for (ll j=1; j<w; j++)
        {
            if (m[i][j]=='.')
            {
                ans[i][j]=(ans[i-1][j]+ans[i][j-1])%MOD;
            }
            else
                ans[i][j]=0;
        }
    }
    cout<<ans[h-1][w-1]%MOD;
}