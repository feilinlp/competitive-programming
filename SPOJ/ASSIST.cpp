#include <iostream>

using namespace std;

bool prima[100001];
int memo[100001];

int main()
{
    for (int i=2; i<100001; i++)
    {
        if (prima[i]==false)
        {
            int x=0, y=i+1;
            while (y<100001)
            {
                if (prima[y]==false)
                    x++;
            
                if (x==i)
                {
                    prima[y]=true;
                    //printf("%d", prima[y]);
                    x=0;
                }
            
                y++;
            }
        }
    }
    int x=1;
    for (int i=2; i<100001; i++)
    {
        if (prima[i]==false)
        {
            //printf("%d", prima[i]);
            memo[x]=i;
            x++;
        }
    }
    int X;
    scanf("%d", &X);
    while (X!=0)
    {
        printf("%d\n", memo[X]);
        scanf("%d", &X);
    }
}