#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;
    char s[n];
    cin >> s;
    vector < vector < vector <long long> > > dp(n, vector < vector <long long> > (26, vector <long long> (26, 0)));
    if (s[0]=='?')
    {
        if (s[1]=='?')
        {
            for (int i=0; i<26; i++)
            {
                for (int j=0; j<26; j++)
                {
                    if (i!=j)
                        dp[1][i][j]=1;
                }
            }
        }
        else
        {
            for (int i=0; i<26; i++)
            {
                if (i!=s[1]-97)
                    dp[1][i][s[1]-97]=1;
            }
        }
    }
    else
    {
        if (s[1]=='?')
        {
            for (int i=0; i<26; i++)
            {
                if (i!=s[0]-97)
                    dp[1][s[0]-97][i]=1;
            }
        }
        else if (s[0]!=s[1])
            dp[1][s[0]-97][s[1]-97]=1;
    }

    for (int i=2; i<n; i++)
    {
        if (s[i]=='?')
        {
            for (int j=0; j<26; j++)
            {
                long long sum=0;
                for (int k=0; k<26; k++)
                {
                    sum += dp[i-1][k][j];
                }
                // printf("%lld\n", sum);
                for (int k=0; k<26; k++)
                {
                    if (j!=k)
                        dp[i][j][k] = (sum - dp[i-1][k][j]) % MOD;
                }
            }
        }
        else
        {
            int c = s[i]-97;
            for (int j=0; j<26; j++)
            {
                if (j!=c)
                {
                    long long sum=0;
                    for (int k=0; k<26; k++)
                    {
                        sum += dp[i-1][k][j];
                    }
                    // printf("%lld\n", sum);
                    dp[i][j][c] = (sum - dp[i-1][c][j]) % MOD;
                }
            }
        }
    }
    long long ans=0;
    for (int i=0; i<26; i++)
    {
        for (int j=0; j<26; j++)
        {
            ans = (ans + dp[n-1][i][j]) %MOD;
        }
    }
    printf("%lld\n", ans);
}
