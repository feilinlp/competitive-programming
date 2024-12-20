#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    stack <int> z;
    for (int t=0; t<T; t++)
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
        else
        {
            if (z.empty())
                printf("Empty!\n");
            else
            {
                int h=z.top();
                printf("%d\n", h);
            }
        }
    }
}