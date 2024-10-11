#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll dp[65][65][2],n,x;
ll rec(ll prev=1,ll sm=0,ll i=0){
    if(i==n)return sm==x;

    ll &ret=dp[i][sm][prev];
    if(~ret)return ret;

    return ret=rec(0,sm,i+1)+rec(1,sm+prev,i+1);
}
int main()
{
Ahmed_Sayed();
while(cin>>n>>x&&n>-1){
memset(dp,-1,sizeof dp);
cout<<rec()<<'\n';
}
}
