#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n;
        scanf("%d", &n);
        vector <int> arr(n+1, 0);
        for (int i=1; i<=n; i++)
        {
            scanf("%d", &arr[i]);
        }
        vector < vector <int> > cycle(n);
        int count=0;
        vector <int> taken(n+1, -1);
        int curr=1, row=0;
        while (count < n)
        {
            if (cycle[row].size()>0)
            {
                if (arr[curr]==cycle[row][0])
                {
                    row++;
                    for (int i=curr; i<=n; i++)
                    {
                        if (taken[arr[i]]==-1)
                        {
                            curr=i;
                            break;
                        }
                    }
                }
                else
                {
                    curr=arr[curr];
                    taken[curr]=row;
                    count++;
                    cycle[row].push_back(curr);
                }
            }
            else
            {
                count++;
                curr=arr[curr];
                cycle[row].push_back(curr);
                taken[curr]=row;
            }
        }
        bool found=false;
        for (int i=2; i<=n; i++)
        {
            if (taken[i]==taken[i-1])
            {
                found=true;
                break;
            }
        }
        if (found)
            printf("%d\n", n-row-2);
        else
            printf("%d\n", n-row);
    }
}