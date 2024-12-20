#include <iostream>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[N][M];
    bool ans = true;
    int satu=0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j]==1)
                satu++;
        }
    }

    if (satu==0)
        printf("NO\n");
    else
        printf("YES\n");
}