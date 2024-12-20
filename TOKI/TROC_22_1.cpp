#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char x[5];
    scanf("%s", &x);
    bool yes=false;
    for (int i=0; i<strlen(x); i++)
    {
        if (x[i]=='0')
        {
            printf("YES\n");
            yes=true;
            break;
        }
    }
    if (yes!=true)
        printf("NO\n");
}