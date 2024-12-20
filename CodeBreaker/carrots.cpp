#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

long long f(long long n, long long k)
{
    return (k-(n%k))*(n/k)*(n/k) + (n%k)*((n/k)+1)*((n/k)+1);
}

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    vector <long long> carrots(n);
    long long curr=0;
    for (long long i=0; i<n; i++)
    {
        scanf("%lld", &carrots[i]);
        curr+=carrots[i]*carrots[i];
    }
    priority_queue <pair <long long, pair <long long, long long> > > cut; //diff, initial length, 
    for (long long i=0; i<n; i++)
    {
        cut.push(make_pair(f(carrots[i], 1)-f(carrots[i], 2), make_pair(carrots[i], 1)));
    }
    for (long long i=0; i<k-n; i++)
    {
        long long diff=cut.top().first;
        long long init=cut.top().second.first;
        long long c=cut.top().second.second+1;
        cut.pop();
        curr -= diff;
        cut.push(make_pair(f(init, c)-f(init, c+1), make_pair(init, c)));
    }
    printf("%lld\n", curr);
}