#include <iostream>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here

    ll r, c;
    cin >> r >> c;
    ll plot[r][c];
    for (ll i=0; i<r; i++)
    {
        for (ll j=0; j<c; j++)
            cin >> plot[i][j];
    }

    ll ans=0;
    for (ll i=1; i<r-1; i++)
    {
        ll possible[c], mi[c], ma[c];
        for (ll j=0; j<c; j++)
        {
            mi[j]=plot[i][j];
            ma[j]=plot[i][j];
            if (plot[i-1][j] > plot[i][j])
                possible[j]=plot[i-1][j];
            else
                possible[j]=-1;
        }
        
        for (ll ii=i; ii < r-1; ii++)
        {
            ll poss[c];
            for (ll j=0; j<c; j++)
                poss[j]=possible[j];
            for (ll j=0; j<c; j++)
            {
                mi[j]=min(mi[j], plot[ii][j]);
                ma[j]=max(ma[j], plot[ii][j]);
                if (plot[ii+1][j] > plot[ii][j] && poss[j]!=-1)
                    poss[j] = min(poss[j], plot[ii+1][j]);
                else
                    poss[j] = -1;
            }
            
            // for (ll j=0; j<c; j++)
            //     cout << ma[j] << " " << mi[j] << " " << poss[j] << endl;

            for (ll j=1; j<c-1; j++)
            {
                ll curma=ma[j];
                // cout << curma << endl;
                for (ll jj=j; jj<c-1; jj++)
                {
                    curma=max(curma, ma[jj]);
                    // cout << curma << endl;
                    bool fail=false;
                    for (ll jjj=j; jjj <= jj; jjj++)
                    {
                        if (poss[jjj]==-1 || curma >=poss[jjj])
                            fail=true;
                    }
                    if (fail)
                        break;
                    // cout << ma[jj] << " " << mi[j-1] << " " << mi[jj+1] << endl;
                    if (curma<min(mi[j-1], mi[jj+1]))
                    {
                        // cout << i << " " << j << " " << ii << " " << jj << " " << curma << " " << ma[jj] << " " << poss[jj] << " " << mi[j-1] << " " << mi[jj+1] << endl;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
