#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    vector <long long> temp(n);
    for (long long i=0; i<n; i++)
    {
        scanf("%lld", &temp[i]);
    }
    long long l=0;
    vector <long long> number;
    while (true)
    {
        if (temp[l]<=0)
            l++;
        else
            break;
    }
    long long r=n-1;
    while (true)
    {
        if (temp[r]<=0)
            r--;
        else
            break;
    }
    for (long long i=l; i<=r; i++)
        number.push_back(temp[i]);
    bool positive=true;
    priority_queue <long long> pos, neg;
    long long sum=0;
    long long curr=0;
    long long no=0;
    for (long long i=0; i<number.size(); i++)
    {
        if (positive)
        {
            if (number[i]>=0)
            {
                sum+=number[i];
                curr+=number[i];
            }
            else
            {
                // printf("%lld\n", curr);
                pos.push(-curr);
                no++;
                curr=number[i];
                positive=false;
            }
        }
        else
        {
            if (number[i]<=0)
            {
                curr+=number[i];
            }
            else
            {
                // printf("%lld\n", curr);
                sum+=number[i];
                positive=true;
                neg.push(curr);
                curr=number[i];
            }
        }
    }
    if (positive)
    {
        no++;
        pos.push(-curr);
    }
    else
    {
        neg.push(curr);
    }

    while (no > k)
    {
        printf("%lld\n", sum);
        long long a=pos.top(), b=neg.top();
        if (a>b)
        {
            sum+=a;
            pos.pop();
        }
        else
        {
            sum+=b;
            neg.pop();
        }
        no--;
    }
    printf("%lld\n", sum);
}

// wrong ans
// 10 1
// -1 2 3 -4 5 -6 7 8 -9 10