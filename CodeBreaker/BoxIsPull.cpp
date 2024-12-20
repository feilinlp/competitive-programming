#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    int x1, y1, x2, y2;
    int h, v;
    for (int i=0; i<t; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        h=x2-x1;
        v=y2-y1;
        if (h<0)
            h=-h;
        if (v<0)
            v=-v;
        
        if (h==0)
            printf("%d\n", v);
        else if (v==0)
            printf("%d\n", h);
        else
            printf("%d\n", h+v+2);
    }
}