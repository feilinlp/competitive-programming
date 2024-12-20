#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        int X, count=0, a;
        scanf("%d", &X);
        for (int i=0; i<X; i++)
        {
            scanf("%d", &a);
            if (a<60)
                count++;
        }
        printf("Case #%d: %d\n", t, count);
    }
}