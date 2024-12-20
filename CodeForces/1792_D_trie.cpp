#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        int trie[n*m][m];
        for (int i=0; i<n*m; i++)
        {
            for (int j=0; j<m; j++)
                trie[i][j]=-1;
        }

        int arr[n][m], pos[n][m];
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                scanf("%d", &arr[i][j]);
                arr[i][j]--;
                pos[i][arr[i][j]]=j;
            }
        }

        // for (int i=0; i<n; i++)
        // {
        //     for (int j=0; j<m; j++)
        //         printf("%d ", pos[i][j]);
        //     printf("\n");
        // }
        // printf("\n");

        int node=1, curr=0;
        for (int i=0; i<n; i++)
        {
            curr=0;
            for (int j=0; j<m; j++)
            {
                if (trie[curr][pos[i][j]]==-1)
                {
                    trie[curr][pos[i][j]]=node;
                    curr=node;
                    node++;
                }
                else
                {
                    curr=trie[curr][pos[i][j]];
                }
            }
            // for (int k=0; k<n*m; k++)
            // {
            //     for (int l=0; l<m; l++)
            //         printf("%d ", trie[k][l]);
            //     printf("\n");
            // }
            // printf("\n");
        }


        for (int i=0; i<n; i++)
        {
            int ans=0;
            int curr=0;
            for (int j=0; j<m; j++)
            {
                if (trie[curr][arr[i][j]]!=-1)
                {
                    ans++;
                    curr=trie[curr][arr[i][j]];
                }
                else
                    break;
            }
            printf("%d ", ans);
        }
        printf("\n");
    }
}