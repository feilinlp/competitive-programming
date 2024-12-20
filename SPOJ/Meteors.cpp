#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector <int> station(m);
    vector < vector <int> > state(n);
    for (int i=0; i<m; i++)
    {
        scanf("%d", &station[i]);
        station[i]--;
        state[station[i]].push_back(i);
    }
    vector <int> target(n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &target[i]);
    }
    int k;
    scanf("%d", &k);
    vector <int> l(k), r(k), a(k);
    for (int i=0; i<k; i++)
    {
        scanf("%d %d %d", &l[i], &r[i], &a[i]);
        l[i]--;
        r[i]--;
    }
    vector <int> le(n, 1), ri(n, k+1);
    vector < vector <int> > arr(k+1);
    for (int i=k+1; i>1; i=(i+1)/2)
    {
        for (int i=0; i<n; i++)
        {
            if (le[i]<ri[i])
                arr[(le[i]+ri[i])/2].push_back(i);
        }
        vector <int> st(2*m, 0);
        for (int i=1; i<k+1; i++)
        {
            if (l[i-1]>r[i-1])
            {
                int x=m;
                while (x>0)
                {
                    st[x]+=a[i-1];
                    x=x/2;
                }
            }
            int x=r[i-1]+m+1;
            while (x>0)
            {
                st[x]-=a[i-1];
                x=x/2;
            }
            x=l[i-1]+m;
            while (x>0)
            {
                st[x]+=a[i-1];
                x=x/2;
            }
            for (int j=0; j<arr[i].size(); j++)
            {
                for (int s=0; s<state[arr[i][j]].size(); s++)
                {
                    s
                }
            }
        }
    }
}