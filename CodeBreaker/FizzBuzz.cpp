#include <cstdio>

using namespace std;

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for (int i=1; i<=n; i++)
    {
        bool A=false, B=false;
        if (i%a==0)
            A=true;
        if (i%b==0)
            B=true;
        if (A && B)
        {
            printf("FizzBuzz\n");
        }
        else if (A)
        {
            printf("Fizz\n");
        }
        else if (B)
        {
            printf("Buzz\n");
        }
        else
            printf("%d\n", i);
    }   
}