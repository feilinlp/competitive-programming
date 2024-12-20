#include <cstdio>

using namespace std;

int main()
{
    int n;
    int a1, a2, b1, b2, c1, c2;
    scanf("%d", &n);
    scanf("%d %d %d %d %d %d", &a1, &a2, &b1, &b2, &c1, &c2);
    //printf("%d %d %d %d %d %d\n", a1, a2, b1, b2, c1, c2);
    bool ans=true;
    if (b1>a1&&c1<a1)
        ans=false;
    else if (b1<a1&&c1>a1)
        ans=false;
    else if (b2<a2&&c2>a2)
        ans=false;
    else if (b2>a2&&c2<a2)
        ans=false;
    
    if (ans==true) 
        printf("YES\n");
    else
        printf("NO\n");
}