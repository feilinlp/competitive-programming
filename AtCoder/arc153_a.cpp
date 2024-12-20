#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int ans[9];
    for (int i=0; i<9; i++)
        ans[i]=0;
    ans[0]++;
    n--;
    ans[0] += n/100000;
    n = n%100000;
    ans[2] += n/10000;
    n = n%10000;
    ans[3] += n/1000;
    n = n%1000;
    ans[4] += n/100;
    n = n%100;
    ans[6] += n/10;
    n = n%10;
    ans[7] += n/1; 
    ans[1] = ans[0];
    ans[5] = ans[4];
    ans[8] = ans[6];
    for (int i=0; i<9; i++)
        printf("%d", ans[i]);
    printf("\n");
}