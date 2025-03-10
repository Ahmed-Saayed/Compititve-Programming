#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+1;
ll n,q,x[N],sparse[N][22];
 
void bul(){
    for(int i=1;i<=n;i++)sparse[i][0]=x[i];
 
    for(int i=1;(1ll<<i)-1<=n;i++){
        for(int j=1;j+(1ll<<i)-1<=n;j++)
            sparse[j][i]=min(sparse[j][i-1],sparse[j+(1ll<<(i-1))][i-1]);
    }
}
 
ll get(int l,int r){
    ll sz = r-l+1,ret=1e9;
    for(int i=21;i>=0;i--){
        if(sz>>i&1){
            ret=min(ret,sparse[l][i]);
            l+=1ll<<i;
        }
    }
    return ret;
}
 
int main()
{
Ahmed_Sayed();
cin>>n>>q;
for(int i=1;i<=n;i++)cin>>x[i];
 
bul();
while(q--){
    ll l,r;cin>>l>>r;
    cout<<get(l,r)<<'\n';
}
}
