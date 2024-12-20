#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>

#define f first
#define s second

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    long long n, m;
    cin >> n >> m;
    long long turn, shift;
    cin >> turn >> shift;
    char arr[n][m];
    priority_queue < pair <long long, pair <long long, long long> > > pq;
    long long minim[n][m];
    for (long long i=0; i<n; i++)
    {
        for (long long j=0; j<m; j++)
        {
            minim[i][j]=-1;
            cin >> arr[i][j];
            if (arr[i][j]=='.')
                pq.push(make_pair(0, make_pair(i, j)));
        }
    }

    long long ans=-1;
    while (!pq.empty())
    {
        long long cost = -pq.top().f;
        long long x = pq.top().s.f, y=pq.top().s.s;
        // cout << cost << " " << x << " " << y << endl;
        if (x < n && y < m && x >=0 && y>=0 && minim[x][y]==-1)
        {
            minim[x][y]=cost;
            long long temp = 1e18;
            if (x > 0) //left -> up
            {
                if (minim[x-1][y]!=-1)
                {
                    temp=min(temp,cost + minim[x-1][y]);
                }
                if (arr[x-1][y]=='.')
                {
                    temp=min(temp, cost);
                }
                else if (arr[x-1][y]=='R')
                    pq.push(make_pair(-cost-turn, make_pair(x-1, y-1)));
                else if (arr[x-1][y]=='L')
                    pq.push(make_pair(-cost-turn, make_pair(x-1, y+1)));
                else if (arr[x-1][y]=='D')
                    pq.push(make_pair(-cost-shift, make_pair(x-2, y)));
            }
            if (x < n-1) //right -> down
            {
                if (minim[x+1][y]!=-1)
                {
                    temp=min(temp,cost + minim[x+1][y]);
                }
                if (arr[x+1][y]=='.')
                {
                    temp=min(cost, temp);
                }
                else if (arr[x+1][y]=='R')
                    pq.push(make_pair(-cost-turn, make_pair(x+1, y-1)));
                else if (arr[x+1][y]=='L')
                    pq.push(make_pair(-cost-turn, make_pair(x+1, y+1)));
                else if (arr[x+1][y]=='U')
                    pq.push(make_pair(-cost-shift, make_pair(x+2, y)));
            }
            if (y > 0)//up -> left
            {
                if (minim[x][y-1]!=-1)
                {
                    temp=min(temp,cost + minim[x][y-1]);
                }
                if (arr[x][y-1]=='.')
                {
                    temp=min(temp,cost);
                }
                else if (arr[x][y-1]=='R')
                    pq.push(make_pair(-cost-shift, make_pair(x, y-2)));
                else if (arr[x][y-1]=='U')
                    pq.push(make_pair(-cost-turn, make_pair(x+1, y-1)));
                else if (arr[x][y-1]=='D')
                    // cout << "Hello\n";
                    pq.push(make_pair(-cost-turn, make_pair(x-1, y-1)));
            }
            if (y < m-1) //down -> right
            {
                if (minim[x][y+1]!=-1)
                {
                    temp=min(temp,cost + minim[x][y+1]);
                }
                if (arr[x][y+1]=='.')
                {
                    temp=min(temp,cost);
                }
                else if (arr[x][y+1]=='L')
                    pq.push(make_pair(-cost-shift, make_pair(x, y+2)));
                else if (arr[x][y+1]=='U')
                    pq.push(make_pair(-cost-turn, make_pair(x+1, y+1)));
                else if (arr[x][y+1]=='D')
                    pq.push(make_pair(-cost-turn, make_pair(x-1, y+1)));
            }
            if (temp!=1e18)
            {
                if (ans == -1)
                    ans=temp;
                else
                    ans=min(ans, temp);
            }
        }
        pq.pop();
    }

    cout << ans << endl;
}
