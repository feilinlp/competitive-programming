#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <int> a(n);
    for (int i=0; i<n; i++
    {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());

    int odd=0, even=0;
    if (a[0]%2==0)
        even++;
    else  
        odd++;

    for (int i=1; i<n; i++)
    {
        if (a[i]%2==0)
            even++;
        else  
            odd++;

        if (a[i]-a[i-1]==0)
        {
            x
        }
        else if (a[i]-a[i-1]==1)
        {
            x
        }
        else if (a[i]-a[i-1]==2)
        {
            x
        }
        else
        {
            x
        }
    }
}