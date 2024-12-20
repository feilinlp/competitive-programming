#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    int f=0, a=0;
    for (int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        if (s=="For")
            f++;
        else
            a++;
    }
    if (f>a)
        cout <<"Yes\n";
    else
        cout <<"No\n";
}