#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    vector <int> num(n), mod(k/2+1, 0);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &num[i]);
        num[i]=num[i]%k;
        if (num[i]<0)
            num[i]+=k;
        
        if (num[i]>k/2)

    }

}