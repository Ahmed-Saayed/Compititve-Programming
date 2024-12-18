#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,m,k,x[18],dp[1<<18][20];
map<pair<int,int>,ll>mp;
ll rec(ll cnt=0,ll mask=0,ll prev=-1){
    if(cnt==m)return 0;

    ll &ret=dp[mask][prev+1];
    if(~ret)return ret;

    ret=0;
    for(ll i=0;i<n;i++){
        if((mask>>i)&1)continue;

        ll o=mp.find({prev+1,i+1})!=mp.end()?mp[{prev+1,i+1}]:0;
            ret=max(ret,x[i]+o+rec(cnt+1,mask|(1<<i),i));
    }
    return ret;
}
int main()
{
Ahmed_Sayed();
cin>>n>>m>>k;
for(int i=0;i<n;i++)cin>>x[i];
while(k--){
    ll a,b,c;cin>>a>>b>>c;
    mp[{a,b}]=c;
}
memset(dp,-1,sizeof dp);
cout<<rec();
}