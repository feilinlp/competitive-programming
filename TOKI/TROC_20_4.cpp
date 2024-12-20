#include <iostream>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N];
    int ans=0;
    scanf("%d", &arr[0]);
    int previous=arr[0];
    for (int i=1; i<N; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i]!=previous)
        {
            ans++;
            previous=arr[i];
        }
    }
    //printf("%d\n", ans);
    if (ans>3)
        printf("NO\n");
    else
        printf("YES\n");
}