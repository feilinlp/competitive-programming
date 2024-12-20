#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    vector <long long> money;
    money.push_back(1000000);
    money.push_back(500000);
    money.push_back(100000);
    money.push_back(50000);
    money.push_back(10000);
    money.push_back(5000);
    money.push_back(1000);
    money.push_back(500);
    money.push_back(100);
    money.push_back(50);
    money.push_back(10);
    money.push_back(5);
    money.push_back(1);
    long long n;
    scanf("%lld", &n);
    long long count=0;
    for (long long i=0; i<13; i++)
    {
        // printf("%lld\n", n);
        count += n/money[i];
        n -= (n/money[i]) * money[i];
    }
    printf("%lld\n", count);
}