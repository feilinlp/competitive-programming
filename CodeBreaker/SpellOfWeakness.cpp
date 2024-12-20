#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, s;
    long long d;
    scanf("%d %lld %d", &n, &d, &s);
    vector <int> e(n), halved(n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &e[i]);
        halved[i]=0;
    }

    long long done=0;
    int pos=0, half=-1;
    int ans=0;
    while (pos<n)
    {
        done+=e[pos];
        ans++;
        if (done>d)
        {
            if (halved[pos]==0)
            {
                done-=e[pos];
                e[pos]=e[pos]/2;
                halved[pos]=1;
                s--;
                ans--;
            }
            else
            {
                if (half==-1)
                    half=pos-1;
                
                while (s>0 && half>0 && done>d)
                {
                    done-=e[half];
                    e[half]=e[half]/2;
                    halved[half]=1;
                    done+=e[half];
                    half--;
                    s--;
                }
                if (done>d)
                {
                    ans--;
                    break;
                }
            }
        }
        else
            pos++;
    }
    printf("%d\n", ans);
}