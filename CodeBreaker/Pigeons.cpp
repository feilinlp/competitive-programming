#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    string act;
    int count=0;
    bool acc=true;
    for (int i=0; i<m; i++)
    {
        cin>>act;
        if (act=="LAND")
            count++;
        else if (act=="LEAVE")
            count--;
        else
            count=0;
        
        if (count<0)
            count=0;
        
        if (count>n)
            acc=false;
    }

    if (acc==false)
        printf("PLAN REJECTED\n");
    else
        printf("PLAN ACCEPTED\n");
}