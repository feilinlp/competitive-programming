#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    stack <int> s;
    int x;
    for (int i=0; i<a; i++)
    {
        scanf("%d", &x);
        while (!s.empty() && x>=s.top())
        {
            s.pop();
        }
        s.push(x);
    }
    while (!s.empty())
    {
        printf("%d\n", s.top());
        s.pop();
    }
}