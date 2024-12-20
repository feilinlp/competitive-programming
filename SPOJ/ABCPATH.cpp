#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int H, W;
    scanf("%d %d", &H, &W);
    int cas=0;
    while ((H!=0)&&(W!=0))
    {
        int ans=0;
        cas++;
        char arr[H][W];
        queue <pair<int, int> > start;
        for (int h=0; h<H; h++)
        {
            for (int w=0; w<W; w++)
            {
                scanf(" %c", &arr[h][w]);
                if (arr[h][w]=='A')
                {
                    start.push(make_pair(h, w));
                }
            }
        }
        while (start.empty()==false)
        {
            int a=start.front().first;
            int b=start.front().second;
            start.pop();
            queue <pair<pair<int, int>, char> > antri;
            antri.push(make_pair(make_pair(a, b), 'A'));
            bool memo[H][W];
            memset(memo, false, sizeof(memo));
            memo[a][b]=true;
            int jwb=0;
            while (antri.empty()==false)
            {
                int x=antri.front().first.first;
                int y=antri.front().first.second;
                char pos=antri.front().second;
                antri.pop();

                if (y<W-1)
                {
                    if ((arr[x][y+1]==pos+1)&&(memo[x][y+1]==false))
                    {
                        antri.push(make_pair(make_pair(x,y+1), pos+1));
                        memo[x][y+1]=true;
                    }

                    if (x>0)
                    {
                        if ((arr[x-1][y+1]==pos+1)&&(memo[x-1][y+1]==false))
                        {
                            antri.push(make_pair(make_pair(x-1,y+1), pos+1));
                            memo[x-1][y+1]=true;
                        }
                    }

                    if (x<H-1)
                    {
                        if ((arr[x+1][y+1]==pos+1)&&(memo[x+1][y+1]==false))
                        {
                            antri.push(make_pair(make_pair(x+1,y+1), pos+1));
                            memo[x+1][y+1]=true;
                        }
                    }
                }

                if (y>0)
                {
                    if ((arr[x][y-1]==pos+1)&&(memo[x][y-1]==false))
                    {
                        antri.push(make_pair(make_pair(x,y-1), pos+1));
                        memo[x][y-1]=true;
                    }

                    if (x>0)
                    {
                        if ((arr[x-1][y-1]==pos+1)&&(memo[x-1][y-1]==false))
                        {
                            antri.push(make_pair(make_pair(x-1,y-1), pos+1));
                            memo[x-1][y-1]=true;
                        }
                    }

                    if (x<H-1)
                    {
                        if ((arr[x+1][y-1]==pos+1)&&(memo[x+1][y-1]==false))
                        {
                            antri.push(make_pair(make_pair(x+1,y-1), pos+1));
                            memo[x+1][y-1]=true;
                        }
                    }
                }

                if (x<H-1)
                {
                    if ((arr[x+1][y]==pos+1)&&(memo[x+1][y]==false))
                    {
                        antri.push(make_pair(make_pair(x+1,y), pos+1));
                        memo[x+1][y]=true;
                    }
                }

                if (x>0)
                {
                    if ((arr[x-1][y]==pos+1)&&(memo[x-1][y]==false))
                    {
                        antri.push(make_pair(make_pair(x-1,y), pos+1));
                        memo[x-1][y]=true;
                    }
                }

                jwb=pos-64;
            }
            ans=max(ans, jwb);
        }
        printf("Case %d: %d\n", cas, ans);
        scanf("%d %d", &H, &W);
    }
}