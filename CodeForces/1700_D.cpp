#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <int> pipe(n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &pipe[i]);
    }
    
    vector <long long> total(n);
    total[0]=pipe[0];
    vector <int> time(n);
    int maxi=0;
    for (int i=1; i<n; i++)
    {
        total[i]=total[i-1]+pipe[i];
        time[i]=total[i]/(i+1);
        if (total[i]%(i+1)!=0)
            time[i]++;
        maxi=max(time[i], maxi);
        //printf("%d\n", maxi);
    }
    int t;
    scanf("%d", &t);
    for (int j=0; j<t; j++)
    {
        int x;
        scanf("%d", &x);
        if (x<maxi)
            printf("-1\n");
        else
        {
            int ans = total[n-1]/x;
            if (total[n-1]%x!=0)
                ans++;
            printf("%d\n", ans);
        }
    }
}