#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int i=0; i<T; i++)
    {
        char arr[500];
        scanf("%s", &arr);
        int panjang=strlen(arr);
        //printf("%d", panjang);
        stack <char> memo;
        int pos=0;
        while (pos<panjang)
        {
            //printf("a");
            if (arr[pos]>='a')
            {
                //printf("1");
                printf("%c", arr[pos]);
            }
            else if ((arr[pos]==')')&&(memo.empty()==false))
            {
                //printf("2");
                printf("%c", memo.top());
                memo.pop();
            }
            else if (arr[pos]!='(')
            {
                //printf("3");
                memo.push(arr[pos]);
            }

            pos++;
        }
        printf("\n");
    }
}