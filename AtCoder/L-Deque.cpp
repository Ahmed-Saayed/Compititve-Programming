#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,x[3001],dp[3001][3001];
ll rec(ll i=0,ll j=n-1){
    if(i>j)return 0;

    ll &ret=dp[i][j];
    if(~ret)return ret;

    return ret=max(x[i]-rec(i+1,j),x[j]-rec(i,j-1));
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=0;i<n;i++)cin>>x[i];

memset(dp,-1,sizeof dp);

cout<<rec();
}
