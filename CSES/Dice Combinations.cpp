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
ll n,dp[(ll)1e6+1];
ll rec(ll i=n){
    if(i<=0)return !i;
 
    ll&ret=dp[i];
    if(~ret)return ret;
 
    ret=0;
    for(int j=1;j<=6;j++)
        ret=(ret+rec(i-j))%mod;
 
    return ret;
}
 
int main()
{
Ahmed_Sayed();
cin>>n;
memset(dp,-1,sizeof dp);
cout<<rec();
}