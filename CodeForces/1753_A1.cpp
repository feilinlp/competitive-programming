#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n;
        scanf("%d", &n);
        int arr[n+1];
        int sum=0;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            if (i%2==0)
                sum+=arr[i];
            else
            {
                arr[i]=-arr[i];
                sum+=arr[i];
            }
        }
        arr[n]=0;

        if (sum%2==0)
        {
            sum/=2;
            bool split=false;
            int curr=n;
            int spl[n];
            for (int i=0; i<n; i++)
                spl[i]=0;
            while (sum!=0 && curr>=0)
            {  
                // printf("s %d\n", sum);
                split=true;
                curr--;
                if ((n-curr)%2==1)
                {
                    sum-=arr[curr];
                    spl[curr]=1;
                }
                else
                {
                    if (sum%2==0 && abs(sum-arr[curr]) < abs(sum) && sum-arr[curr]!=0)
                    {
                        sum-=arr[curr];
                        spl[curr]=1;
                    }
                    else
                    {
                        spl[curr]=0;
                    }
                }
            }
            int count=0, c=0;
            if (split && sum==0)
            {
                for (int i=0; i<n; i++)
                {
                    if (spl[i]!=c)
                        count++;
                    c=spl[i];
                }
                printf("%d\n", count+1);
                c=0;
                printf("1 ");
                for (int i=0; i<n; i++)
                {
                    if (spl[i]!=c)
                    {
                        printf("%d\n%d ", i, i+1);
                        c=spl[i];
                    }
                }
                printf("%d\n", n);
            }
            else if (sum==0)
                printf("1\n1 %d\n", n);
            else
                printf("-1\n");

        }
        else
        {
            printf("-1\n");
        }
    }
}