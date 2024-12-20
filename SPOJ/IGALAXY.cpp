#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        //printf("ats t=%d\n", t);
        int M;
        scanf("%d", &M);
        map <int, string> kata;
        map <string, int> angka;
        vector <int> list[2*M+1];
        string a, b;
        int x=1;
        for (int i=1; i<=M; i++)
        {
            cin>>a>>b;
            if (angka.count(a)!=1)
            {
                angka[a]=x;
                kata[x]=a;
                x++;
            }
            if (angka.count(b)!=1)
            {
                angka[b]=x;
                kata[x]=b;
                x++;
            }
            list[angka[a]].push_back(angka[b]);
            list[angka[b]].push_back(angka[a]);
        }

        queue <int> antri;
        cin>>a>>b;
        int arr[3][x];
        memset(arr, -1, sizeof(arr));
        arr[1][angka[a]]=1;
        arr[2][angka[a]]=0;
        bool ketemu=false;
        antri.push(angka[a]);
        int akhir=angka[b];
        
        while (antri.empty()==false)
        {
            vector <string> memo;
            
            int x=antri.front();
            //printf("x: %d\n", x);
            if (x==akhir)
            {
                ketemu=true;
                break;
            }
            int y=list[x].size();
            antri.pop();
            for (int i=0; i<y; i++)
            {
                int tujuan = list[x][i];
                if (arr[1][tujuan]==-1)
                {
                    memo.push_back(kata[tujuan]);
                    arr[1][tujuan]=arr[1][x]+1;
                    arr[2][tujuan]=x;
                    //printf("%d %d\n", arr[1][list[x][i]], arr[2][list[x][i]]);
                }
            }
            sort(memo.begin(), memo.end());
            int z=memo.size();
            for (int i=0; i<z; i++)
            {
                //printf("push: %d\n", angka[memo[i]]);
                antri.push(angka[memo[i]]);
            }
        }
        
        int m;
        if (ketemu==true)
            m=arr[1][angka[b]];
        else
            m=-1;
        printf("Scenario #%d: %d\n", t, m);
        string jwban[m+1];
        jwban[m]=b;
        for (int i=m-1; i>=1; i--)
        {
            jwban[i]=kata[arr[2][angka[jwban[i+1]]]];
        }
        for (int i=1; i<=m; i++)
        {
            cout<<jwban[i];
            if (i<m)
                printf(" ");
            else
                printf("\n");
        }
        
        //printf("---bawah t=%d\n", t);
    }
}