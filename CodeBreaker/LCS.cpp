#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    int x=a.length();
    int y=b.length();
    int arr[x+1][y+1];
    for (int i=0; i<=x; i++)
    {
        arr[i][0]=0;
        arr[0][i]=0;
    }

    for (int i=1; i<=x; i++)
    {
        for (int j=1; j<=y; j++)
        {
            if (a[i-1]==b[j-1])
                arr[i][j]=arr[i-1][j-1]+1;
            else
            {
                arr[i][j]=max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    printf("%d\n", arr[x][y]);
}