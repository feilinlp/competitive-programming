#include <cstdio>

using namespace std;

int ans=1;
void exp (int a, int b, int m)
{  
    if (b>1)
        exp(a, b/2, m);
    ans=((long long)ans*ans)%m;
    if (b&1)
        ans=((long long)ans*a)%m;
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int a, b, m;
        scanf("%d %d %d", &a, &b, &m);
        ans=1;
        exp(a, b, m);
        printf("%d\n", ans);
    }
}