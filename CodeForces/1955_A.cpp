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
        int n, s, d;
        scanf("%d%d%d", &n, &s, &d);
        if (s*2 <= d)
            printf("%d\n", n*s);
        else
        {
            printf("%d\n", (n-n%2)/2 * d + (n%2)*s);
        }
    }
}
