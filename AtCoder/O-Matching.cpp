#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,x[22][22],dp[1<<22][22],mod=1e9+7;
ll rec(ll mask=0,ll i=0){
    if(i==n)return 1;

    ll &ret=dp[mask][i];
    if(~ret)return ret;

    ret=0;
    for(int o=0;o<n;o++)if(!((mask>>o)&1)&&x[i][o])ret=(ret+rec(mask|(1<<o),i+1))%mod;
    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>x[i][j];
memset(dp,-1,sizeof dp);
cout<<rec()%mod;
}
