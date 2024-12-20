#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    queue <int> z;
    for (int i=0; i<T; i++)
    {
        int X;
        scanf("%d", &X);
        if (X==1)
        {
            int A;
            scanf("%d", &A);
            z.push(A);
        }
        else if (X==2)
        {
            if (z.empty()==false)
                z.pop();
        }
        else if (X==3)
        {
            if (z.empty())
                printf("Empty!\n");
            else
                printf("%d\n", z.front());
        }
    }
}