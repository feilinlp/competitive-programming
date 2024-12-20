#include <iostream>
#include <math.h>

using namespace std;

bool prima[10000001];
int memo[10000001];

int main()
{
    for (int i=0; i<10000001; i++)
    {
        prima[i]=true;
    }
    for (int i=2; i<10000001; i++)
    {
        for (int j=2; j<10000001; j++)
        {
            if (i*j>10000000)
                break;
            prima[i*j]=false;
        }
    }
    int x=1;
    for (int i=2; i<10000001; i++)
    {
        if (prima[i]==true)
        {
            memo[x]=i;
            x++;
        }
    }
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int X;
        scanf("%d", &X);
        printf("%d\n", memo[X]);
    }
}
