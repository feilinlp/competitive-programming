#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int f[n+1];
    f[0]=0;
    f[1]=1;
    for (int i=2; i<n+1; i++)
    {
        f[i]=(f[i-2]+f[i-1])%998244353;
    }
    for (int i=0; i<n+1; i++)
    {
        printf("%d\n", f[i]);
    }
}