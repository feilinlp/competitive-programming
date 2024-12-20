#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    bool ans=true;
    deque <char> q;
    char x;
    for (int i=0; i<n; i++)
    {
        scanf(" %c", &x);
        if (x=='(' || x=='[' || x=='{')
        {
            q.push_back(x);
            //printf("%c ", q.front());
        }
        else
        {
            if (q.empty())
            {
                ans=false;
                break;
            }  
            if (x==')' && q.back()=='(')
            {
                q.pop_back();
            }
            else if (x==']' && q.back()=='[')
            {
                q.pop_back();
            }
            else if (x=='}' && q.back()=='{')
            {
                q.pop_back();
            }
            else
            {
                ans=false;
                break;
            }
        }
    }
    if (ans==true && q.empty())
        printf("Valid\n");
    else
        printf("Invalid\n");
}