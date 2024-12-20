#include <cstdio>
#include <vector>

using namespace std;

int knightx[]={
    -2, -1, 1, 2, -2, -1, 1, 2
}, knighty[]= {
    1, 2, 2, 1, -1, -2, -2, -1
};

int main()
{
    int k;
    scanf("%d", &k);
    k++;
    vector <unsigned> in(65, 0);
    in[0]=1;
    vector < vector <unsigned> > t(65, vector <unsigned> (65, 0));
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            for (int k=0; k<8; k++)
            {
                if (i+knightx[k]>=0 && i+knightx[k]<8)
                {
                    if (j+knighty[k]>=0 && j+knighty[k]<8)
                    {
                        t[j*8+i][(j+knighty[k])*8+i+knightx[k]]++;
                    }
                }
            }
        }
    }
    for (int i=0; i<65; i++)
    {
        t[64][i]=1;
    }
    while (k>0)
    {
        if (k%2==1)
        {
            vector <unsigned> temp(65, 0);
            for (int i=0; i<65; i++)
            {
                for (int j=0; j<65; j++)
                {
                    temp[i]+=t[i][j]*in[j];
                }
            }
            in=temp;
        }
        vector < vector <unsigned> > temp(65, vector <unsigned> (65, 0));
        for (int i=0; i<65; i++)
        {
            for (int j=0; j<65; j++)
            {
                for (int k=0; k<65; k++)
                {
                    temp[i][k]+=t[i][j]*t[j][k];
                }
            }
        }
        t=temp;
        k=k/2;
    }
    printf("%u\n", in[64]);
}