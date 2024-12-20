#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    string s[n];
    map <string, int> m;
    for (int i=0; i<n; i++)
    {
        cin >> s[i];
        for (int j=1; j<=s[i].length(); j++)
        {
            if (!m.count(s[i].substr(0,j)))
                m[s[i].substr(0, j)]=1;
            else
                m[s[i].substr(0,j)]++;
        }
    }
    for (int i=0; i<n; i++)
    {
        int l=0, r=s[i].length(), mid;
        while (l<=r)
        {
            mid = (l+r)/2;
            // cout << "search " << i <<" "<< m[s[i].substr(0,mid+1)]<<endl;
            if (m[s[i].substr(0, mid+1)]>1)
                l=mid+1;
            else
                r=mid-1;
        }
        if (l>s[i].length())
            l=s[i].length();
        cout << l << endl;
    }
}