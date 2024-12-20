#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, x, y;
    cin >> b >> a >> y >> x;
    priority_queue < pair < int, pair <int, int> > > mw;
    
    int p[a][b];
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
        {
            char t;
            cin >> t;
            if (t=='.')
            {
                p[i][j]=0;
            }
            else
                p[i][j]=-1;
        }
    }
    p[a-x][--y]=1;
    int maks=1;
    mw.push(make_pair(0, make_pair(a-x, y)));
    while (!mw.empty())
    {
        int length=-mw.top().first;
        int tx=mw.top().second.first, ty=mw.top().second.second;
        // printf("tx ty %d %d\n", tx, ty);
        // for (int i=0; i<a; i++)
        // {
        //     for (int j=0; j<b; j++)
        //         printf("%d ", p[i][j]);
        //     printf("\n");
        // }
        // printf("\n");
        mw.pop();
        if (tx>0 && p[tx-1][ty]==0)
        {
            p[tx-1][ty]=1;
            maks=max(maks, length+1);
            mw.push(make_pair(-length-1, make_pair(tx-1, ty)));
        }  
        if (ty>0 && p[tx][ty-1]==0)
        {
            p[tx][ty-1]=1;
            maks=max(maks, length+1);
            mw.push(make_pair(-length-1, make_pair(tx, ty-1)));
        }
        if (tx<a-1 && p[tx+1][ty]==0)
        {
            p[tx+1][ty]=1;
            maks=max(maks, length+1);
            mw.push(make_pair(-length-1, make_pair(tx+1, ty)));
        }
        if (ty<b-1 && p[tx][ty+1]==0)
        {
            p[tx][ty+1]=1;
            maks=max(maks, length+1);
            mw.push(make_pair(-length-1, make_pair(tx, ty+1)));
        }
        if (tx>0 && ty>0 && p[tx-1][ty-1]==0)
        {
            p[tx-1][ty-1]=1;
            maks=max(maks, length+1);
            mw.push(make_pair(-length-1, make_pair(tx-1, ty-1)));
        }
        if (tx<a-1 && ty>0 && p[tx+1][ty-1]==0)
        {
            p[tx+1][ty-1]=1;
            maks=max(maks, length+1);
            mw.push(make_pair(-length-1, make_pair(tx+1, ty-1)));
        }
        if (tx<a-1 && ty<b-1 && p[tx+1][ty+1]==0)
        {
            p[tx+1][ty+1]=1;
            maks=max(maks, length+1);
            mw.push(make_pair(-length-1, make_pair(tx+1, ty+1)));
        }
        if (tx>0 && ty<b-1 && p[tx-1][ty+1]==0)
        {
            p[tx-1][ty+1]=1;
            maks=max(maks, length+1);
            mw.push(make_pair(-length-1, make_pair(tx-1, ty+1)));
        }
    }
    cout << maks << endl;
}