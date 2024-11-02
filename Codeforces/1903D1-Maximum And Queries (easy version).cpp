#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();
int n,q;cin>>n>>q;
vector<ll>x(n);
for(auto&i:x)cin>>i;

while(q--){
    ll k;cin>>k;

    vector<ll>y=x;
    for(ll i=60;~i;i--){
        ll pw=(1ll<<i),sm=0;

        for(auto&j:y){
            if(!(j>>i&1))
                sm+=pw-j%pw;
          
            if(sm>k)break;
        }
        
        if(sm<=k){
            k-=sm;

        for(auto&j:y)
            if(!(j>>i&1))
                j+=pw-j%pw;
        }
    }

    ll ans=(1ll<<61)-1;
    for(auto i:y)ans&=i;

    cout<<ans<<'\n';
}
}
