#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    vector <int> a(t);
    for (int i=0; i<t; i++)
        scanf("%d", &a[i]);
    vector <int> mul(t);
    //printf("%d\n", __LINE__);
    vector <int> ans;
    int pos=0;
    //printf("%d\n", __LINE__);
    long long fin=0;
    vector <int> x(t);
    for (int i=0; i<t; i++)
        scanf("%d", &x[i]);
    for (int i=0; i<t; i++)
    {
        //printf("%d\n", __LINE__);
        if (x[i]==1)
        {
            //printf("%d\n", __LINE__);
            ans.push_back(a[i]);
            mul[pos]=t-i;
            //printf("%d\n", __LINE__);
            pos++;
        }
        else
        {
            //printf("%d\n", __LINE__);
            fin+=(long long)a[i]*(t-i);
            //printf("%lld\n", fin);
            //printf("%d\n", __LINE__);
        }
        //printf("%d\n", __LINE__);
    }
    //printf("%lld\n", fin);
    int l=ans.size();
    sort(ans.begin(), ans.end());
    for (int i=0; i<l; i++)
    {
        fin+=(long long)mul[i]*ans[l-1-i];
        //printf("%lld\n", fin);
    }
    //printf("%d\n", __LINE__);
    printf("%lld\n", fin);
} 