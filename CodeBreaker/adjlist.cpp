#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    vector < vector <int> > al(a);
    for (int i=0; i<b; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        al[--x].push_back(--y);
        al[y].push_back(x);
    }
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<al[i].size(); j++)
            printf("%d ", al[i][j]+1);
        printf("\n");
    }
}