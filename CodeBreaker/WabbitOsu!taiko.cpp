#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    string s;
    cin>>s;
    for (int i=1; i<=n; i++)
    {
        if (n%(2*i+1)==0)
            printf("%d ", n/(2*i+1));
        else
            printf("%d ", n/(2*i+1)+1);
    }
}