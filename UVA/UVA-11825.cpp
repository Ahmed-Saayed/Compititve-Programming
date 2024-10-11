#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll cnt(ll n){
    ll ans=0;
    while(n){
        ans++;
        n&=n-1;
    }
    return ans;
}
ll ans[1<<17],dp[1<<17];
ll rec(ll mask){
    ll&ret=dp[mask];
    if(~ret)return ret;

    ret=0;
    for(int j=mask;j;j=(j-1)&mask)
        if(ans[j])ret=max(ret,1+rec(mask^j));
    return ret;
}
int main()
{
Ahmed_Sayed();

ll n,id=1;
while(cin>>n&&n){
memset(dp,-1,sizeof dp),memset(ans,0,sizeof ans);
ll adj[n]={};

for(int i=0;i<n;i++){
    ll m;cin>>m;
    while(m--){
        ll o;cin>>o;
        adj[i]|=1<<o;
    }
    adj[i]|=1<<i;
}

for(int i=0;i<1<<n;i++){
    ll o=0;
    for(int j=0;j<n;j++)if((i>>j)&1)o|=adj[j];
    if(cnt(o)==n)ans[i]=1;
}
cout<<"Case "<<id++<<": "<<rec((1<<n)-1)<<'\n';
}
}
