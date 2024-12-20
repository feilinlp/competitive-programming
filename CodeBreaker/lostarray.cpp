#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector < pair <int, int> > arr(n, make_pair(1e9+1, -1));
    for (int i=0; i<m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        
        if (arr[a].first==1e9+1)
        {
            arr[a].first=c;
            arr[a].second=b;

            if (arr[b].first==1e9+1)
            {
                arr[b].first = c;
                arr[b].second = a;
            }     
        }
        else
        {
            if (arr[b].first==1e9+1)
            {
                arr[b].first = c;
                arr[b].second = a; 
            }
            else
            {
                if (arr[arr[b].second].second == b)
                {
                    arr[a].first=c;
                    arr[a].second=b;
                }
                if (arr[arr[a].second].second == a)
                {
                    arr[b].first = c;
                    arr[b].second = a;
                }
            }
        }
    }
    for (int i=0; i<n; i++)
    {
        if (arr[i].first != 1e9+1)
            printf("%d ", arr[i].first);
        else
            printf("1 ");
    }
}