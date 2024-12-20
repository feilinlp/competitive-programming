#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int l;
        cin >> l;
        string num;
        int ans[l];
        cin >> num;
        for (int j=0; j<l; j++)
        {
            ans[j]=0;
        }
        if (num[0]!='9')
        {
            for (int j=0; j<l; j++)
            {
                ans[j]='9'-num[j];
            }
        }
        else
        {
            //ans[l-1]=('9'-num[l-1]+2)%10;
            for (int j=l-1; j>=0; j--)
            {
                if (num[j+1]>'1' && j!=l-1)
                    num[j]++;
                ans[j]+=('9'-num[j]+2)%10;
                /*if (num[j]<'2')
                {
                    ans[j]+='1'-num[j];
                    num[j-1]--;
                }
                else
                {
                    ans[j]+='9'-num[j]+1;
                }*/
            }
        }
        for (int j=0; j<l; j++)
        {
            cout << ans[j];
        }
        cout<<endl;
    }
}