#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <cstring>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n;
    cin >> n;
    ll sparseTable[n+5][25];
    for (ll i=0; i<n+5; i++)
    {
        for (ll j=0; j<25; j++)
            sparseTable[i][j]=-1;
    }
    map <ll, ll> ans;
    for (ll i = 0; i < n; i ++)
    {
        cin >>  sparseTable[i][0];
    }
    for (ll I = 1; I < 25; I ++)
    {
        for (ll i = 0; i+(1<<I) <= n; i ++)
        {
            sparseTable[i][I]=__gcd(sparseTable[i][I-1], sparseTable[i+(1<<I-1)][I-1]);
        }
    }

    ll fastLog[n+5];
    fastLog[0]=-1;
    for(ll i = 1; i <= n; i ++)
        fastLog[i]=fastLog[i/2]+1;


    for (ll l=0; l<n; l++)
    {
        for (ll r=l; r<n; r++)
        {
            ll layer=fastLog[r-l+1];
            ll x=__gcd(sparseTable[l][layer], sparseTable[ r-(1<<layer)+1][layer]);
            if (x==1)
            {
                ans[1]+=n-r;
                break;
            }
            if (ans.count(x)>0)
                ans[x]++;
            else
                ans[x]=1;
        }
    }


    // for (ll i=0; i<5; i++)
    // {
    //     for (ll j=0; j<n; j++)
    //         cout << sparseTable[j][i] << " ";
    //     cout << endl;
    // }
    
    ll q;
    cin >> q;
    for (ll i=0; i<q; i++)
    {
        ll x;
        cin >> x;
        // cout << "ans";
        if (ans.count(x)>0)
            cout << ans[x]<< endl;
        else
            cout << 0 << endl;
    }
}