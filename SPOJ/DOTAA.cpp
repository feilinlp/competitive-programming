#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int M, N, D;
        scanf("%d %d %d", &M, &N, &D);
        priority_queue <int> q;
        for (int m=0; m<M; m++)
        {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        bool cek=true;
        for (int n=0; n<N; n++)
        {
            int a=q.top()-D;
            q.pop();
            if (a>0)
                q.push(a);
            else
            {
                cek=false;
                break;
            }
        }
        if (cek==false)
            printf("NO\n");
        else
            printf("YES\n");
    }
}