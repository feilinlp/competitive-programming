#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    for (int i=0; i<a; i++)
    {
        string s;
        cin >> s;
        int l = s.length();
        cout << s;
        for (int j=0; j<l; j++)
        {
            cout << s[l-1-j];
        }
        cout <<"\n";
    }
}