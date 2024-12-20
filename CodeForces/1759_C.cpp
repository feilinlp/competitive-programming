#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int l, r, x, a, b;
        scanf("%d %d %d", &l, &r, &x);
        scanf("%d %d", &a, &b);
        int diff = b-a, count = 0;
        bool ans = true;
        if (a != b)
        {
            if (b + x > r && b - x < l) 
                ans = false;
            if (a + x > r && a - x < l)
                ans = false;
        }
        while (a != b && ans)
        {
            diff = b-a;
            if (b > a)
            {
                if (x <= diff)
                {
                    a += diff;
                }
                else
                {
                    if (a - x >= l)
                        a -= x;
                    else
                        a = r;
                }
            }
            else
            {
                if (x <= -diff)
                {
                    a += diff;
                }
                else
                {
                    if (a + x <= r)
                        a += x;
                    else
                        a = l;
                }
            }
            count++;
        }
        if (ans)
            printf("%d\n", count);
        else
            printf("-1\n");
    }   
}