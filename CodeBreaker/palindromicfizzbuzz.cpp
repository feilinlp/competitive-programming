#include <cstdio>
#include <vector>
#define ll long long

using namespace std;

bool check(ll x)
{
    vector <ll> a;
    while (x > 0)
    {
        a.push_back(x%10);
        x/=10;
    }
    for (ll i=0; i<a.size()/2+1; i++)
    {
        if (a[i] != a[a.size()-1-i])
            return false;
    }
    return true;
}

int main()
{
    ll a, b;
    scanf("%lld %lld", &a, &b);
    for (ll i=a; i<=b; i++)
    {
        if (check(i))
        {
            printf("Palindrome!\n");
        }
        else
            printf("%lld\n", i);
    }
}