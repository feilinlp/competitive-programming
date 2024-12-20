#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    int t;
    scanf(" %d", &t);
    map <char, int> pos;
    char a;
    string word;
    int length;
    int temp;
    for (int i=0; i<t; i++)
    {
        int ans=0;
        for (int j=0; j<26; j++)
        {
            scanf(" %c", &a);
            pos[a]=j;
            //printf("%d ", pos[a]);
        }
        cin>>word;
        //printf("%c ", word[1]);
        length = word.length();
        //printf("length = %d\n", length);
        for (int j=0; j<length-1; j++)
        {
            temp=pos[word[j]]-pos[word[j+1]];
            //printf("%d ", pos[word[j]]);
            if (temp<0)
                temp=-temp;
            ans+=temp;
            //printf("%d ", ans);
        }
        printf("%d\n", ans);
    }
}