#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

bool com (pair < pair <ll, ll>, ll>  a, pair < pair <ll, ll>, ll> b)
{
    return a.first.first < b.first.first;
}

bool comp (pair < pair <ll, ll>, ll>  a, pair < pair <ll, ll>, ll> b)
{
    return a.first.first > b.first.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    ll n;
    cin >> n;
    pair < pair <ll, ll>, ll> bucket[n], rim[n], buck[n];
    bool used[n];
    for (ll i=0; i<n; i++)
    {
        used[i]=false;
        ll a,b;
        cin >> a >> b;
        bucket[i] = make_pair(make_pair(a, b), i);
        buck[i] = make_pair(make_pair(a, b), i);
        rim[i] = make_pair(make_pair(b, a), i);
    }
    sort(bucket, bucket+n, com);
    sort(rim, rim+n, comp);
    sort(buck, buck+n, comp);

    // cout << endl;
    // for (ll i=0; i<n; i++)
    // {
    //     cout << bucket[i].first << " " << bucket[i].second << endl;
    // }

    ll ans=0, posb=0, posr=0, curr=1e9, posbb=n-1;
    while (posb < n && posr < n)
    {
        while (used[bucket[posb].second])
            posb++;
        while (used[rim[posr].second])
            posr++;
        while (used[buck[posr].second])
            posbb--;

        if (rim[posr].first.first <= curr)
        {
            ans++;
            used[rim[posr].second]=true;
            curr=rim[posr].first.second;
            posr++;
        }
        else
        {
            if (bucket[posb].first.second < bucket[pos])
        }
    }
    if (posr < n)
        ans++;
    cout << ans << endl;
}