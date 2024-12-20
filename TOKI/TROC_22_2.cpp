#include <cstdio>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int curr=97;
    for (int i=0; i<N; i++)
    {
        char x=curr;
        printf("%c", x);
        curr++;
        if (curr>99)
            curr=97;
    }
    printf("\n");
}