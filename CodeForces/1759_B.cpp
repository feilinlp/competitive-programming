#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int arr[101];
    for (int i=0; i<101; i++)
    {
        arr[i] = (i * (i+1)) / 2;
    }
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int m, s;
        scanf("%d %d", &m, &s);
        int sum = 0;
        int maxim = 0;
        bool pos = true;
        vector <int> app(101, 0);
        for (int j=0; j<m; j++)
        {
            int x;
            scanf("%d", &x);
            app[x]++;
            if (x < 1 || app[x]>1)
                pos = false;
            sum += x;
            maxim = max(maxim, x);
        }
        sum += s;
        // printf("sum = %d\n", sum);
        int l = 0, r = 101;
        bool ans = false;
        while (l <= r && !ans && r > 0)
        {
            // printf("lr = %d %d\n", l, r);
            int mid = (l+r) / 2;
            if (arr[mid] > sum)
                r = mid - 1;
            else if (arr[mid] < sum)
                l = mid + 1;
            else
            {
                // printf("m = %d %d\n", maxim, mid);
                if (maxim <= mid)
                    ans = true;
                else
                {
                    break;
                }
            }
        }
        if (ans && pos)
            printf("YES\n");
        else
            printf("NO\n");
    }
}