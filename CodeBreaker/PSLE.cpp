#include <cstdio>

using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    if (a<20)
        printf("U\n");
    else if (a<35)
        printf("E\n");
    else if (a<50)
        printf("D\n");
    else if (a<60)
        printf("C\n");
    else if (a<75)
        printf("B\n");
    else if (a<91)
        printf("A\n");
    else
        printf("A*\n");
}