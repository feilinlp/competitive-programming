#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        long long n, h;
        scanf("%lld %lld", &n, &h);
        long long temp[n];
        for (long long j=0; j<n; j++)
        {
            scanf("%lld", &temp[j]);
        }
        sort(temp, temp+n);
        long long use = 0, count1 = 0, power = h;
        //223
        while (count1 < n)
        {
            if (power > temp[count1])
            {
                power += temp[count1]/2;
                count1++;
            }
            else if (use < 3)
            {
                use++;
                if (use < 3)
                    power*=2;
                else
                    power*=3;
            }
            else
            {
                break;
            }
        }
        while (use < 3)
        {
            use++;
            if (use < 3)
                power*=2;
            else
                power*=3;
        }

        use = 0, power = h;
        long long count2=0;
        while (count2 < n)
        {
            if (power > temp[count2])
            {
                power += temp[count2]/2;
                count2++;
            }
            else if (use < 3)
            {
                use++;
                if (use != 2)
                    power*=2;
                else
                    power*=3;
            }
            else
            {
                break;
            }
        }
        while (use < 3)
        {
            use++;
            if (use != 2)
                power*=2;
            else
                power*=3;
        }

        use = 0, power = h;
        long long count3=0;
        while (count3 < n)
        {
            if (power > temp[count3])
            {
                power += temp[count3]/2;
                count3++;
            }
            else if (use < 3)
            {
                use++;
                if (use != 1)
                    power*=2;
                else
                    power*=3;
            }
            else
            {
                break;
            }
        }
        while (use < 3)
        {
            use++;
            if (use != 1)
                power*=2;
            else
                power*=3;
        }

        printf("%lld\n", max(count1, max(count2, count3)));
    }
}