#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    vector <int> power(31);
    power[0]=0;
    power[1]=1;
    for (int i=2; i<31; i++)
    {
        power[i]=2*power[i-1];
    }
    int t;
    cin >> t;
    for (int T=0; T<t; T++)
    {
        int ans=0;
        int n;
        cin >> n;
        int prev=1e9;
        while (n>0)
        {
            int minus=0;
            if (n>=prev)
            {
                for (int i=prev; i<=n; i++)
                {
                    minus += power[i];
                }
            }
            else
                minus += power[n];
            prev=n;
            ans+=minus;
            cout << "- " << minus << endl;
            cout.flush();
            cin >> n;
        }
        cout << "! " << ans << endl;
        cout.flush();
    }
}