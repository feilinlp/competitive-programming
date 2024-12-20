#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int S;
        scanf("%d", &S);
        map <int, string> kata;
        map <string, int> angka;
        vector < pair<int, int> > list[S+1];
        int x=1;
        for (int i=0; i<S; i++)
        {
            string kota;
            cin>>kota;

            if (angka.count(kota)!=1)
            {
                angka[kota]=x;
                kata[x]=kota;
                x++;
            }

            int C;
            scanf("%d", &C);
            for (int j=0; j<C; j++)
            {
                int K, H;
                scanf("%d %d", &K, &H);
                list[angka[kota]].push_back(make_pair(H, K));
            }
        }

        int Q;
        scanf("%d", &Q);
        for (int i=0; i<Q; i++)
        {
            priority_queue < pair<int, int> > antri;
            string a, b;
            cin>>a>>b;
            int A, B;
            A=angka[a];
            B=angka[b];
            antri.push(make_pair(0, A));
            int arr[x];
            memset(arr, -1, sizeof(arr));
            while (antri.empty()==false)
            {
                int step=-antri.top().first;
                int asal=antri.top().second;
                antri.pop();
                if (asal==B)
                {
                    printf("%d\n", step);
                    break;
                }
                if (arr[asal]==-1)
                {
                    arr[asal]=step;
                    int z=list[asal].size();
                    for (int j=0; j<z; j++)
                    {
                        if (arr[list[asal][j].second]==-1)
                        {
                            antri.push(make_pair(-(list[asal][j].first+step), list[asal][j].second));
                        }
                    }
                }
            }
        }
    }
}