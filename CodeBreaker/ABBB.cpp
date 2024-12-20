#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t); 
    for (int i=0; i<t; i++)
    {
        deque <char> x;
        string y;
        cin>>y;
        int len=y.length();
        for (int j=0; j<len; j++)
        {
            //printf("%c ", y[j]);
            if (!x.empty() && y[j]=='B')
            {
                x.pop_back();
            }
            else
            {
                x.push_back(y[j]);
                //printf("%c ", x.back());
            }
        }

        int ans=0;
        while (!x.empty())
        {
            x.pop_back();
            ans++;
        }
        printf("%d\n", ans);
    }

}