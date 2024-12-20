#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <int> num(n+1);
    vector <int> list(n+1, 1e9);
    list[0]=0;
    int pos=1;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &num[i]);
        if (num[i]>list[pos-1])
        {
            
            list[pos]=num[i];
            pos++;
        }
        else
        {
            int x=pos-1;
            while (x>=1)
            {
                if (num[i]>list[x-1] && num[i]<list[x])
                {
                    list[x]=num[i];
                    break;
                }
                x--;
            }
        }
        /*for (int j=0; j<pos; j++)
        {
            printf("%d ", list[j]);
        }
        printf("\n");*/
    }
    printf("%d\n", pos-1);
}