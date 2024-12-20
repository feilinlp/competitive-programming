#include <iostream>
#include <queue>
#include <cstdio>
#include <utility>

using namespace std;

int main()
{
	int S, P, B;
	scanf("%d %d %d", &S, &P, &B);
	int arr[2][S];
	priority_queue < pair<pair<int, int>, int> > urutan;
	
	for (int i=0; i<S; i++)
	{
		scanf("%d", &arr[0][i]);
	}
	for (int i=0; i<S; i++)
	{
		scanf("%d", &arr[1][i]);
		int x=arr[0][i]-arr[1][i];
		if (x>=0)
		{
			urutan.push(make_pair(make_pair(x, 2), i)); //physics > biology
		}
		else
		{
			x=-x;
			urutan.push(make_pair(make_pair(x, 1), i));
		}
	}
	
	long long total=0;
	while (!urutan.empty())
	{
		int pel=urutan.top().first.second;
		int index=urutan.top().second;
		urutan.pop();
		if (pel==2 and P>0)
		{
			P--;
			total+=arr[0][index];
		}
		else if (pel==1 and B>0)
		{
			B--;
			total+=arr[1][index];
		}
		else if (pel==2 and P<=0)
		{
			B--;
			total+=arr[1][index];
		}
		else if (pel==1 and B<=0)
		{
			P--;
			total+=arr[0][index];
		}
	}
	printf("%d\n", total);
}
		
