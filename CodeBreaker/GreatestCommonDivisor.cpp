#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int x, int y)
{
    if (x%y==0)
        return y;
    
    return gcd(y, x%y);
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    //printf("%d\n", __gcd(x, y));
    if (x<y)
    {
        int temp=x;
        x=y;
        y=temp;
    }
    printf("%d\n", gcd(x, y));
}