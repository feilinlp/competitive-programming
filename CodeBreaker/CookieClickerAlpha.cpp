#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        double c, f, x;
        scanf("%lf %lf %lf", &c, &f, &x);
        double speed=2;
        double buy=0, no=0, curr=0;
        while (true)
        {
            no=x/speed;
            buy=c/speed + x/(speed+f);
            if (no<=buy)
            {
                printf("Case #%d: %.7lf\n", i+1, curr+no);
                break;
            }
            else
            {
                curr+=c/speed;
                speed+=f;
            }
        }
    }
}