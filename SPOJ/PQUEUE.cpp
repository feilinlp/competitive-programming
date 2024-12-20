#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int N, M;
        scanf("%d %d", &N, &M);
        int arr[2][N];
        priority_queue <int> memo;
        for (int i=0; i<N; i++)
        {
            arr[1][i]=0;
            scanf("%d", &arr[0][i]);
            memo.push(arr[0][i]);
        }
        arr[1][M]=1;
        int pos=0, count=0;
        while (arr[1][M]==1)
        {
            if (arr[0][pos]!=0)
            {
                if (arr[0][pos]==memo.top())
                {
                    arr[0][pos]=0;
                    memo.pop();
                    count++;
                    arr[1][pos]=0;
                }
            }
            pos++;
            if (pos==N)
                pos=0;
        }
        printf("%d\n", count);
    }
}