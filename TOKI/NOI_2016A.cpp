#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    int array[B];
    for (int i=0; i<B; i++)
    {
        scanf("%d", &array[i]);
    }
    sort(array, array+B);

    int total=0, pos=0;
    while (total<=A)
    {
        if (pos==B)
            break;
        total+=array[pos];
        if (total>A)
            break;
        pos++;
    }
    printf("%d\n", pos);
}