#include <iostream>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i=0; i<b; i++)
    {
        int m, n;
        scanf("%d %d", &m, &n);
    }
    int ans = a*2 - 3;
    ans = ans-b;
    printf("%d\n", ans);
}