#include <cstdio>

using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    int x;
    for (int i=0; i<a*a*a*a; i++)
        scanf("%d", &x);
    a=a*a*(a*a+1)/2;
    printf("%d\n", a);
}