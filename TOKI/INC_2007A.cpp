#include <iostream>
#include <string.h>

using namespace std;

int main() 
{
	char kata[26];
	while (scanf("%s", &kata)!=EOF)
	{
		int panjang = strlen(kata);
		int posisi[panjang];
		for (int i=0; i<panjang; i++)
		{
			posisi[kata[i]-97]=i;
		}
		int count=0, pos=0;
		while (pos<panjang-1)
		{
			if (kata[pos]!=pos+97)
			{
				count++;
				posisi[kata[pos]-97]=posisi[pos];
				kata[posisi[pos]]=kata[pos];
                posisi[pos]=pos;
				kata[pos]=pos+97;
                printf("%s\n", kata);
			}
			pos++;
		}
		/*for (int i=0; i<panjang; i++)
			printf("%c", kata[i]);
        printf("\n");*/
		//printf("%d\n", count);
	}
}