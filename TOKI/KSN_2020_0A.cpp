#include <cstdio>

using namespace std;

/*int f(int a, int b, int m)
{
    if (b==0)
        return 1;
    
    return (a, b-1, m);
}*/

int main()
{
    int a, b, m;
    scanf("%d %d %d", &a, &b, &m);
    int ans=0;
    /*if (a==3 && b==3 && m==100)
    {
        printf("83\n");
    }
    else */if (a%m==0)
    {
        printf("0\n");
    }
    else if (m==2)
    {
        if (a%2==1)
            printf("1\n");
        else
            printf("0\n");
    }
    else if (m==3)
    {
        if ()
    }

}