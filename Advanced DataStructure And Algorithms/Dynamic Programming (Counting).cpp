#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,m,k1,k2,dp[101][101][11][11],mod=1e8;
ll rec(ll prev=0,ll prev2=0,ll i=0,ll j=0,ll idx=0){	//118D-Caesar's Legions 
    if(i==n&&j==m)return 1;

    ll&ret=dp[i][j][prev][prev2];
    if(~ret)return ret;

    ret=0;
    if(i<n&&prev+1<=k1)
	ret+=rec(prev+1,0,i+1,j,idx+1)%mod;
    if(j<m&&prev2+1<=k2)
	ret+=rec(0,prev2+1,i,j+1,idx+1)%mod;
    
    return ret%mod;
}

int main()
{
Ahmed_Sayed();
cin>>n>>m>>k1>>k2;
memset(dp,-1,sizeof dp);

cout<<rec();
}