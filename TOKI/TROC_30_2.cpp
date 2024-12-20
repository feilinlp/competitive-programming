#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <int> a(n), b(n), ra, rb;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    int prev=a[0];
    ra.push_back(prev);
    for (int i=1; i<n; i++)
    {
        if (a[i]!=prev)
        {
            ra.push_back(a[i]);
            prev=a[i];
        }
    }
    for (int i=0; i<n; i++)
    {
        scanf("%d", &b[i]);
    }
    prev=b[0];
    rb.push_back(prev);
    for (int i=1; i<n; i++)
    {
        if (b[i]!=prev)
        {
            rb.push_back(b[i]);
            prev=b[i];
        }
    }
    int posa=0, posb=0;
    while (posa < ra.size() && posb < rb.size())
    {
        if (ra[posa]==rb[posb])
        {
            // printf("%d\n", posb);
            posb++;
        }
        posa++;
    }
    if (posb>=rb.size())
        printf("YES\n");
    else
        printf("NO\n");
}