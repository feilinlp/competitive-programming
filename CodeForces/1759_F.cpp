#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n, p;
        scanf("%d %d", &n, &p);
        vector <int> check(p, 0);
        int last=0;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &last);
            check[last]++;
        }
        
    }
}