#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int prevd=0, prevp=0, prev=0;
    int dp[n][2];

    bool poss=true;
    for (int i=0; i<n; i++)
    {
        int d, p;
        scanf("%d %d", &d, &p);
        int changed=d-prevd, changep=p-prevp;

        int a = changed+changep, b=changed-changep;
        if (changep<0)
            changep=-changep;
        if (a%2==1 || b%2==1 || changed < changep)
            poss=false;
        
        a/=2;
        b/=2;
        dp[i][0]=a;
        dp[i][1]=b;
        prevd=d;
        prevp=p;
    }

    vector <int> ans;
    int plus=2, pos=0;
    while (plus==2 && pos < n)
    {
        if (dp[pos][0]==0)
        {
            plus=0;
            break;
        }
        else if (dp[pos][1]==0)
        {
            plus=1;
            break;
        }
        pos++;
    }
    // for (int i=0; i<n; i++)
    // {
    //     printf("dp %d %d\n", dp[i][0], dp[i][1]);
    // }

    if (plus!=2)
    {
        if (pos%2==1)//0 or 1 dk
        {
            plus=1-plus;
        }
    }

    
    int total=0;
    for (int i=0; i<n; i++)
    {
        if (plus==0)
        {
            total -= dp[i][1];
            if (dp[i][0]!=0)
            {
                plus=1;
                ans.push_back(total);
                total = dp[i][0];
            }
        }
        else
        {
            total += dp[i][0];
            if (dp[i][1]!=0)
            {
                plus=0;
                ans.push_back(total);
                total = -dp[i][1];
            }
        }
    }
    if (total!=0)
        ans.push_back(total);


    if (!poss)
        printf("-1\n");
    else
    {
        printf("%d\n", ans.size());
        for (int i=0; i<ans.size(); i++)
        {
            if (ans[i]>0)
                printf("%d\t+\n", ans[i]);
            else
                printf("%d\t-\n", -ans[i]);
        }
    }
}