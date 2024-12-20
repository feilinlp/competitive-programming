#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    int curr=0;
    int x;
    for (int i=0; i<t; i++)
    {
        scanf("%d", &x);
        curr=curr+x;
    }
    if (curr%2==0)
        printf("Yes\n");
    else
        printf("No\n");
}