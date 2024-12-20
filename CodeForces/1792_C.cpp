#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define rep(i,n) for (int i = 0; i < n; i++)
int t, n, a[200010];
int main(){
   cin>>t;
   while(t--){
      cin>>n;
      int loc;
      
      rep(i,n){
         cin>>a[i];
         if(a[i]==(n+1)/2)loc=i;
      }
      int l;

      int cur = (n+1)/2;

      for(int i=loc-1; i>=0; i--){
         if(a[i]==cur-1)
            cur--;
      }
      int numl=(n+1)/2-cur;
      //cout<<cur<<endl;
      cur = (n+1)/2;
      for(int i=loc+1; i<n; i++){
         if(a[i]==cur+1){
            cur++;
         }
      }
      //cout<<cur<<endl;
      if(n%2==0)numl++;
      int numr=cur-(n+1)/2;
      //cout<<numl<<' '<<numr<<endl;
      cout<<n/2-min(numl,numr)<<endl;
      
   }

}