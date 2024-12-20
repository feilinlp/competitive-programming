#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    //printf("%d\n", __LINE__);
    vector <int> b(m);
    for (int i=0; i<m; i++)
        scanf("%d", &b[i]);
    //printf("%d\n", __LINE__);
    sort(b.begin(), b.end());
    int maxi=b[m-1], mini=0, ans;
    //printf("%d\n", __LINE__);
    while (mini<maxi)
    {
        // printf("%d %d\n", mini, maxi);
        //printf("%d\n", __LINE__);
        ans=(maxi+mini)/2;
        int u=upper_bound(b.begin(), b.end(), ans)-b.begin();
        //printf("%d\n", __LINE__);
        int count=u;
        for (int i=u; i<m; i++)
        {
            //printf("%d\n", __LINE__);
            if (b[i]%ans==0)
                count+=b[i]/ans;
            else
                count+=b[i]/ans + 1;
            //printf("%d\n", __LINE__);
        }
        // printf("count %d\n", count);
        //printf("%d\n", __LINE__);
        if (count==n)
        {
            maxi=ans;
        }
        else if (count < n)
            maxi=ans;
        else
            mini=ans+1;
    }
    printf("%d\n", (mini+maxi)/2);
}