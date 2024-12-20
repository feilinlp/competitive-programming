#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int T=0; T<t; T++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        map <string, int> store;
        vector < vector <int> > row(n, vector <int> (m));
        for (int i=0; i<n; i++)
        {
            vector <int> pos(m);
            for (int j=0; j<m; j++)
            {
                scanf("%d", &row[i][j]);
                pos[row[i][j]-1]=j;
            }
            string ins="";
            for (int j=0; j<m; j++)
                ins.append("o");
            // cout << ins;
            for (int j=0; j<m; j++)
            {
                // printf("%d\n", pos[j]);
                ins[pos[j]]=j+65;
                // cout << ins << endl;
                store[ins]=1;
            }
        }

        for (int i=0; i<n; i++)
        {
            vector <int> look(m);
            for (int j=0; j<m; j++)
            {
                look[row[i][j]-1]=j;
            }
            vector <int> pos(m);
            for (int j=0; j<m; j++)
            {
                pos[look[j]]=j;
            }
            string ins="";
            for (int j=0; j<m; j++)
                ins.append("o");
            int ans=0;
            for (int j=0; j<m; j++)
            {
                ins[pos[j]]=j+65;
                if (store.count(ins))
                    ans++;
                else
                    break;
            }
            printf("%d ", ans);
        }
        printf("\n");
    }
}