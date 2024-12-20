#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t=0; t<T; t++)
    {
        string x;
        cin >> x;
        int l=x.length();
        int open=0, close=0;
        int total=l/2;
        bool ans1=true, ans2=true;
        x[0]='(';
        x[l-1]=')';
        for (int i=0; i<l; i++)
        {
            if (x[i]=='(')
                open++;
            else if (x[i]==')')
                close++;
        }
        int open1=open, close1=close;
        int left=0, right=0;
        for (int i=0; i<l; i++)
        {
            if (x[i]=='(')
                left++;
            else if (x[i]==')')
                right++;
            else
            {
                if (left > right)
                {
                    if (open < total)
                    {
                        if (close < total)
                        {
                            ans1=false;
                            break;
                        }
                        left++;
                        open++;
                    }
                    else
                    {
                        right++;
                        close++;
                    }
                }
                else
                {
                    left++;
                    open++;
                }
            }
        }

        left=0, right=0;
        for (int i=l-1; i>=0; i--)
        {
            if (x[i]=='(')
                left++;
            else if (x[i]==')')
                right++;
            else
            {
                if (right > left)
                {
                    if (close1 < total)
                    {
                        if (open1 < total)
                        {
                            ans2=false;
                            break;
                        }
                        right++;
                        close1++;
                    }
                    else
                    {
                        left++;
                        open1++;
                    }
                }
                else
                {
                    right++;
                    close1++;
                }
            }
        }

        if (ans1 || ans2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}