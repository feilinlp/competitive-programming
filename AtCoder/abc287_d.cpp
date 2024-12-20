#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s, t;
    cin >> s;
    cin >> t;
    int sl = s.length(), tl=t.length();
    int left=0, right = sl - tl; //[0, left), [right, s)
    int wrong=0;
    for (int i=right; i<sl; i++)
    {
        if (s[i]!='?' && t[i-right]!='?' && s[i]!=t[i-right])
        {
            wrong++;
        }
    }
    
    for (int i=0; i<=tl; i++)
    {
        if (wrong > 0)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
        if (s[left]!='?' && t[left]!='?' && s[left]!=t[left])
        {
            wrong++;
        }
        left++;
        if (s[right]!='?' && t[right-sl+tl]!='?' && s[right]!=t[right-sl+tl])
        {
            wrong--;
        }
        right++;
    }
}