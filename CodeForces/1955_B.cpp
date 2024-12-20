#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cstring>
#include <math.h>
#include <numeric>

using namespace std;

int main(){
	int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        int n, c, d;
        scanf("%d%d%d", &n, &c, &d);
        int arr[n*n];
        for (int j=0; j<n*n; j++) {
            scanf("%d", &arr[j]);
        }
        sort(arr, arr+n*n);
        int comp[n*n];
        for (int j=0; j<n; j++)
        {
            int first = arr[0] + j*d;
            for (int k=0; k<n; k++)
            {
                comp[n*j+k] = first + k*c;
            }
        }
        sort(comp, comp+n*n);
        bool ans = true;
        for (int j=0; j<n*n; j++)
        {
            if (comp[j] != arr[j])
            {
                ans = false;
                break;
            }
        }
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
