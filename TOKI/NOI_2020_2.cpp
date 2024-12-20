#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, D;
    scanf("%d %d", &N, &D);
    int stn[4][N+1];
    for (int i=1; i<=N; i++)
    {
        scanf("%d %d %d", stn[1][i], stn[2][i], stn[3][i]);
    }

    int pos=1;
    bool urut=true;
    while (true)
    {
        if (pos==N)
        {
            pos=1;
            urut=true;
        }

        if (stn[1][pos]>stn[1][pos+1])
        {
            for (int i=1; i<=3; i++)
            {
                tmp=stn[i][pos];
                stn[i][pos]=stn[i][pos+1];
                stn[i][pos+1]=tmp;
                urut=false;
            }
        }
        pos++;

        if ((pos==N)&&(urut==true))
        {
            break;
        }
    }

    for (int i=1; i<=N; i++)
}