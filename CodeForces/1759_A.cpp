#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        string s;
        cin >> s;
        bool ans = true;
        int j=0;
        while (ans && j<s.length())
        {
            if (s[j] != 'Y' && s[j] != 'e' && s[j]!='s')
                ans = false;
            else if (j > 0)
            {
                if (s[j] == 'Y' && s[j-1] != 's')
                    ans = false;
                else if (s[j] == 'e' && s[j-1] != 'Y')
                    ans = false;
                else if (s[j] == 's' && s[j-1] != 'e')
                    ans = false;
            }
            j++;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
