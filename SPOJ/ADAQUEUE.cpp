#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int main()
{
    int Q;
    scanf("%d", &Q);
    deque <int> d;
    bool role=true;
    for (int i=0; i<Q; i++)
    {
        string kata;
        cin >> kata;
        if (kata=="back")
        {
            if (d.empty()==false)
            {
                if (role==false)
                {
                    printf("%d\n", d.front());
                    d.pop_front();
                }
                else
                {
                    printf("%d\n", d.back());
                    d.pop_back();
                }
            }
            else
                printf("No job for Ada?\n");
        }
        else if (kata=="front")
        {
            if (d.empty()==false)
            {
                if (role==true)
                {
                    printf("%d\n", d.front());
                    d.pop_front();
                }
                else
                {
                    printf("%d\n", d.back());
                    d.pop_back();
                }
            }
            else
                printf("No job for Ada?\n");
        }
        else if (kata=="reverse")
        {
            if (role==true)
                role=false;
            else
                role=true;
        }
        else if (kata=="push_back")
        {
            int A;
            scanf("%d", &A);
            if (role==true)
                d.push_back(A);
            else
                d.push_front(A);
        }
        else if (kata=="toFront")
        {
            int A;
            scanf("%d", &A);
            if (role==false)
                d.push_back(A);
            else
                d.push_front(A);
        }
    }
}