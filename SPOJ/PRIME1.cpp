#include <iostream>
#include <math.h>

using namespace std;

int A, B;
void cek(int a)
{
    if (a>B)
        return;
    
    if (a==1)
        cek(a+1);
    else if (a==2)
    {
        printf("%d\n", a);
        cek(a+1);
    }
    else if (a%2==1)
    {
        bool x=true;
        for (int i=3; i<=sqrt(a); i+=2)
        {
            if (a%i==0)
            {
                x=false;
                break;
            }
        }
        if (x==true)
            printf("%d\n", a);
        cek(a+2);
    }
    else
        cek(a+1);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        scanf("%d %d", &A, &B);
        cek(A);
        printf("\n");
    }
}