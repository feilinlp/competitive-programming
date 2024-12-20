#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int hasil=0, prev=0, a, curr=0;
    scanf("%d", &a);
    do
    {
        if (prev<a)
        {
            if (curr>=0)
                curr=curr+a-prev;
            else
            {
                hasil=max(hasil, curr);
                curr=0;
            }
        }
        else if (prev<a)
        {
            if (curr<=0)
                curr=curr+prev-a;
            else
            {
                hasil=max(hasil, curr);
                curr=0;
            }
        }
        
        prev=a;
    }
    while(scanf("%d", &a)==1);

    if (hasil<0)
        hasil=-hasil;
    printf("%d", hasil);
}