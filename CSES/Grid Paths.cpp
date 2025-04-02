#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){ 
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll mod=1e9+7;
ll n,dp[1000][1000];
char x[1000][1000];
ll rec(ll i=0,ll j=0){
    if(i==n||j==n||x[i][j]=='*')return 0;
    if(i==n-1&&j==n-1)return 1;
 
    ll&ret=dp[i][j];
    if(~ret)return ret;
 
    ret=0;
    return ret=(ret+rec(i+1,j)+rec(i,j+1))%mod;
}
 
int main()
{
Ahmed_Sayed();
memset(dp,-1,sizeof dp);
cin>>n;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)cin>>x[i][j];
 
cout<<rec();
}