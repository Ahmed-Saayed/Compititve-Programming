#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll a,n,m,point[2005],x[2005],dp[2005][2005][2];
ll rec(ll i=0,ll prev=0,bool taken=0){
    if(point[i]&&!taken&&!x[i])return 1e18;
    if(i==a)return 0;

    ll&ret=dp[i][prev][taken];
    if(~ret)return ret;

    ret=1e18;
    if(point[i]&&!taken)return ret=x[i]+rec(i+1,i,1);
    if(point[i]!=point[i+1]||(!point[i]&&!point[i+1]))ret=rec(i+1,0,0);

    if(x[i]){
        if(taken){
            if(x[i]<x[prev])prev=i;
        }
        else prev=i,taken=1;
}

    if(taken)ret=min(ret,x[prev]+rec(i+1,prev,taken));

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>a>>n>>m;
memset(dp,-1,sizeof dp);

int o=0;
while(n--){
    ll l,r;cin>>l>>r,o++;
    for(int j=l;j<=r;j++)point[j]=o;
}

while(m--){
    ll o,w;cin>>o>>w;
    if(x[o])x[o]=min(x[o],w);
    else x[o]=w;
}

ll ans=rec();
cout<<(ans>=1e18?-1:ans);
}