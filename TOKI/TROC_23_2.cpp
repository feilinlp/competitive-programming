#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int ans=n/10;
    if (ans>0 && n%10!=9)
        ans--;
    if (ans>9)
        ans=9;
    printf("%d\n", ans);
}