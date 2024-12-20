#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector < pair <int, int> > temp(n);
    vector <bool> drown(n, false);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &temp[i].first);
        temp[i].second=i;
    }
    sort(temp.begin(), temp.end());
    int maxi=1, curr=1;
    for (int i=0; i<n; i++)
    {
        if (temp[i].second==0)
        {
            if (drown[temp[i].second+1])
                curr--;
        }
        else if (temp[i].second==n-1)
        {
            if (drown[temp[i].second-1])
                curr--;
        }
        else
        {
            if (drown[temp[i].second-1] && drown[temp[i].second+1])
                curr--;
            else if (!drown[temp[i].second-1] && !drown[temp[i].second+1])
                curr++;
        }
        drown[temp[i].second]=true;
        if (temp[i+1].first!=temp[i].first)
        {
            maxi=max(maxi, curr);
            // printf("maxi = %d\n", maxi);
        }
    }
    printf("%d\n", maxi);
}
