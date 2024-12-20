#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int am[a][a];
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<a; j++)
            am[i][j]=0;
    }
    for (int i=0; i<b; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        am[--x][--y]=1;
        am[y][x]=1;
    }
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<a; j++)
            printf("%d", am[i][j]);
        printf("\n");
    }
}