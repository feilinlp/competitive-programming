#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <long long> coorx(n), coory(n);
    for (int i=0; i<n; i++)
    {
        scanf("%lld %lld", &coorx[i], &coory[i]);
    }
    sort(coorx.begin(), coorx.end());
    sort(coory.begin(), coory.end());
    if (n%2==1)
    {
        printf("%lld %lld\n", coorx[n/2], coory[n/2]);
    }
    else
    {
        printf("%lld %lld\n", (coorx[n/2]+coorx[n/2-1])/2, (coory[n/2]+coory[n/2-1])/2);
    }
}