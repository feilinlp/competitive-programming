#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int M, N;
        scanf("%d %d", &M, &N);
        queue <pair <int, pair<int, int>>> antri;
        bool memo[M][N];
        char arr[M][N];
        for (int m=0; m<M; m++)
        {
            for (int n=0; n<N; n++)
            {
                scanf(" %c", &arr[m][n]);
                if (arr[m][n]=='$')
                {
                    antri.push(make_pair(m, make_pair(n, 0)));
                    memo[m][n]=true;
                }
            }
        }
        memset(memo, false, sizeof(memo));
        int ans=-1;
        while (antri.empty() == false)
        {
            int x=antri.front().first;
            int y=antri.front().second.first;
            int step=antri.front().second.second;
            //printf("%d %d %d\n", x, y, step);
            antri.pop();
            if (y<N-1)
            {
                if ((arr[x][y+1]!='*')&&(memo[x][y+1]==false))
                {
                    antri.push(make_pair(x, make_pair(y+1, step+1)));
                    memo[x][y+1]=true;
                    //printf("%d %d %d\n", x, y+1, step+1);
                }
            }

            if (y>0)
            {
                if ((arr[x][y-1]!='*')&&(memo[x][y-1]==false))
                {
                    antri.push(make_pair(x, make_pair(y-1, step+1)));
                    memo[x][y-1]=true;
                    //printf("%d %d %d\n", x, y-1, step+1);
                }
            }

            if (x<M-1)
            {
                if ((arr[x+1][y]!='*')&&(memo[x+1][y]==false))
                {
                    antri.push(make_pair(x+1, make_pair(y, step+1)));
                    memo[x+1][y]=true;
                    //printf("%d %d %d\n", x+1, y, step+1);
                }
            }

            if (x>0)
            {
                if ((arr[x-1][y]!='*')&&(memo[x-1][y]==false))
                {
                    antri.push(make_pair(x-1, make_pair(y, step+1)));
                    memo[x-1][y]=true;
                    //printf("%d %d %d\n", x-1, y, step+1);
                }
            }

            if (arr[x][y]=='#')
            {
                ans=step;
                break;
            }
        }
        printf("%d\n", ans);
    }
}