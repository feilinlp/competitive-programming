#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector < pair<int, int> > time(n);
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &time[i].second, &time[i].first); //end time then start time
    }
    sort(time.begin(), time.end());
    int count=0, curr=0;
    for (int i=0; i<n; i++)
    {
        if (time[i].second >= curr)
        {
            count++;
            curr = time[i].first;
        }
    }
    printf("%d\n", count);
}