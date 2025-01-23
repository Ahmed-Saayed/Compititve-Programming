#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll mod=1e9+7;
ll n,x,v[100],dp[(ll)1e6+1];
ll rec(ll sm=x){
    if(sm<=0)return !sm;
 
    ll&ret=dp[sm];
    if(~ret)return ret;
 
    ret=0;
    for(int i=0;i<n;i++)
        ret=(ret+rec(sm-v[i]))%mod;
 
 return ret;
}
 
int main()
{
Ahmed_Sayed();
cin>>n>>x;
memset(dp,-1,sizeof dp);
for(int i=0;i<n;i++)cin>>v[i];
cout<<rec();
}
