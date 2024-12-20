#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	bool ada[N+1];
	vector < pair < int, int > > jarak[N+1];
	vector <int> kota;
	int jumlah=0;
	memset(ada, false, sizeof(ada));
	
	for (int i=1; i<N; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (c<=K)
		{
			ada[a]=true;
			ada[b]=true;
			jarak[a].push_back(make_pair(b, c));
			jarak[b].push_back(make_pair(a, c));
		}
	}
	
	int sisa=0;
	for (int i=1; i<N+1; i++)
	{
		if (ada[i]==false)
		{
			kota.push_back(i);
			jumlah++;
		}
		else
			sisa++;
	}
	
	while (sisa>0)
	{
		priority_queue < pair <int, int> > banyak;
		for (int i=1; i<N+1; i++)
		{
			if (ada[i]==true)
				banyak.push(make_pair(jarak[i].size(), i));
		}
		
		priority_queue < pair<int, int> > panjang;
		panjang.push(make_pair(0, banyak.top().second));
		
		while (panjang.empty()==false)
		{
			int x=-panjang.top().first;
			int y=panjang.top().second;
			sisa--;
			if (x==0)
			{
				kota.push_back(y);
				//printf("%d %d\n", y, x);
				jumlah++;
			}
			ada[y]=false;
			panjang.pop();
			
			int m=jarak[y].size();
			for (int i=0; i<m; i++)
			{
				int a=x+jarak[y][i].second;
				//printf("%d %d\n", a, jarak[y][i].first);
				if (a<=K)
					panjang.push(make_pair(-a, jarak[y][i].first));
			}
		}
	}
	
	printf("%d\n", jumlah);
	int n=kota.size();
	for (int i=0; i<n; i++)
	{
		printf("%d", kota[i]);
		if (i!=n-1)
			printf(" ");
		else
			printf("\n");
	}
}
		
