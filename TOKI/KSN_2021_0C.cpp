#include <cstdio>

using namespace std;

int main()
{
    int q;
    scanf("%d", &q);
    int w=0;
    int in;
    for (int i=0; i<q; i++)
    {
        scanf("%d", &in);
        if (in==i-w+1)
        {
            printf("BENAR\n");
            fflush(stdout);
        }
        else
        {
            printf("SALAH\n");
            w=i+1;
            fflush(stdout);
        }
    }
}