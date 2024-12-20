#include <iostream>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int N;
        scanf("%d", &N);
        int arr[N][N];
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                for (int k=0; k<N; k++)
                {
                    arr[j][k]=min(arr[j][i]+arr[i][k], arr[j][k]);
                }
            }
        }
        int ans=0;
        int R;
        scanf("%d", &R);
        for (int i=0; i<R; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            ans=ans+arr[a-1][b-1];
        }
        printf("Case #%d: %d\n", t+1, ans);
    }
}