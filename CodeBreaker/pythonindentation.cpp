#include <iostream>
#define MOD 1e9+7

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here

    int N;
    cin >> N;
    int f=0, ans=1, prevf=-1;
    for (int i=0; i<N; i++)
    {
        char x;
        cin >> x;
        if (prevf==0)
        {
            ans += f * (f+1) / 2;
        }
        if (x=='f')
        {
            prevf=1;
            f++;
        }
        else
        {
           prevf--;
        }
    }
    printf("%d\n", ans);
}
