#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int getlevel(char x)
{
    if( x == '(')
        return 0;
    else if(x == '+' || x=='-')
        return 1;
    else if(x == '*' || x=='/')
        return 2;
    else if(x == '^' )
        return 3;
}


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
        int pos=0, level=0, top=0;
        while (pos<panjang)
        {
            //printf("a");
            if (arr[pos]>='a' && arr[pos]<='z')
            {
                //printf("1");
                printf("%c", arr[pos]);
            }
            else if (arr[pos]=='(')
            {
                memo.push(arr[pos]);
            }
            else if (arr[pos]==')')
            {
                while(memo.top() != '(')
                {
                    printf("%c", memo.top());
                    memo.pop();
                }
                memo.pop(); //pop kurung buka                
            }
            else if ( memo.empty() || getlevel(arr[pos]) > getlevel(memo.top()))
            {
                memo.push(arr[pos]);
            }
            else if ( getlevel(arr[pos]) <= getlevel(memo.top()))
            {
                while ( getlevel(arr[pos]) <= getlevel(memo.top())) 
                {
                    printf("%c", memo.top());
                    memo.pop();   
                    if(memo.empty())
                        break;
                }
                memo.push(arr[pos]);
            }

            pos++;
        } //end of while proses

        while (memo.empty()==false)
        {
            printf("%c", memo.top());
            memo.pop();
        }
        printf("\n");
    }
}