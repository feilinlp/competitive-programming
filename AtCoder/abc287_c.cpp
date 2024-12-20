#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int path[n][2];
    int used[n];
    for (int i=0; i<n; i++)
    {
        path[i][0]=-1;
        path[i][1]=-1;
        used[i]=0;
    }

    bool ans=true;
    for (int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (path[a][0]==-1)
            path[a][0]=b;
        else if (path[a][0]!=b)
        {
            if (path[a][1]!=-1)
                ans=false;
            path[a][1]=b;
        }
        
        if (path[b][0]==-1)
            path[b][0]=a;
        else if (path[b][0]!=a)
        {
            if (path[b][1]!=-1)
                ans=false;
            path[b][1]=a;
        }
    }
    int first=-1, second=-1;
    for (int i=0; i<n; i++)
    {
        if (path[i][0]==-1)
        {
            ans=false;
            break;
        }
        else if (path[i][1]==-1)
        {
            if (first==-1)
                first=i;
            else if (second==-1)
                second=i;
            else
            {
                ans=false;
                break;
            }
        }
    }

    int count=1;
    while (first != second && count < n)
    {
        used[first]=1;
        if (used[path[first][0]]==0)
        {
            first = path[first][0];
        }
        else if (path[first][1]!=-1 && used[path[first][1]]==0)
        {
            first = path[first][1];
        }
        count++;
    }
    
    
    if (ans && count==n)
        printf("Yes\n");
    else
        printf("No\n");
}