#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int x[N], y[N];
    for (int i=0; i<N; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    sort(x, x+N);
    sort(y, y+N);
    int a,b;
    if (N%2==0)
    {
        a=(x[N/2 - 1]+ x[N/2])/2;
        b=(y[N/2 - 1]+ y[N/2])/2;
    }
    else
    {
        a=x[N/2];
        b=y[N/2];
    }

    printf("%d %d\n", a, b);
}