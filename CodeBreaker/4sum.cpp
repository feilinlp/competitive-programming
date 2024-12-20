#include <cstdio>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    set <int> w, x, y, z;
    int m;
    for (int i=0; i<a; i++)
    {
        scanf("%d", &m);
        w.insert(m);
    }
    for (int i=0; i<b; i++)
    {
        scanf("%d", &m);
        x.insert(m);
    }
    for (int i=0; i<c; i++)
    {
        scanf("%d", &m);
        y.insert(m);
    }
    for (int i=0; i<d; i++)
    {
        scanf("%d", &m);
        z.insert(m);
    }

    int ans1, ans2, ans3, ans4;
    bool found=false;

    set<int>::iterator i, j, k;
    for (i=w.begin(); i!=w.end(); i++)
    {
        for(j=x.begin(); j!=x.end(); j++)
        {
            for (k=y.begin(); k!=y.end(); k++)
            {
                int curr=*i + *j + *k;
                auto pos = z.find(-curr);
                if (pos != z.end())
                {
                    found=true;
                    ans1=*i;
                    ans2=*j;
                    ans3=*k;
                    ans4=*pos;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found)
            break;
    }
    printf("%d %d %d %d\n", ans1, ans2, ans3, ans4);
}