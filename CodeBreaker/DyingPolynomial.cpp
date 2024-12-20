#include <cstdio>
#include <map>

using namespace std;

long long arr[500001], ar[500001];

int binser(long long x)
{
    int l=0, r=500001, mid=(l+r)/2;
    //printf("%d\n", __LINE__);
    while (l<r)
    {
        mid=(l+r)/2;
        if (mid!=500000 && arr[mid]<=x && arr[mid+1]>x)
            break;
        else if (arr[mid]>x)
            r=mid-1;
        else if (arr[mid]<x)
            l=mid;
        //printf("%d\n", __LINE__);
    }
    return (l+r)/2;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<500001; i++)
    {
        arr[i]=(long long)i*((long long)i*i);
        ar[i]=(long long)i*i;
    }
    for (int i=0; i<t; i++)
    {
        //printf("%d\n", __LINE__);
        int a, b, c;
        long long d;
        scanf("%d %d %d %lld", &a, &b, &c, &d);
        int m=binser((long long)d/a);
        //printf("%d\n", __LINE__);
        map<int, long long> ans;
        bool minus=false;
        while (true)
        {
            ans[m]=(long long)a*arr[m]+(long long)b*ar[m]+(long long)c*m;
            if (ans[m]<=d && minus==true)
            {
                m++;
                //printf("%d\n", __LINE__);
                break;
            }
            else if (ans[m]<d)
            {
                //printf("%d\n", __LINE__);
                m++;
            }
            else if (ans[m]>d)
            {
                m--;
                //printf("%d\n", __LINE__);
                minus=true;
            }
            else
                break;
        }
        printf("%d\n", m);
    }
}