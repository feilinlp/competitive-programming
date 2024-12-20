#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define rep(i,n) for (int i = 0; i < n; i++)
int t, a,b,c,d;
int main(){
   cin>>t;
   while(t--){
      cin>>a>>b>>c>>d;
      if(a==0)
        cout<<1<<endl;
      else{
        int ma=max(b,c), mi=min(b,c);
        cout<<2*mi+a+min(ma-mi+d,a+1)<<endl;
        }
    }
}