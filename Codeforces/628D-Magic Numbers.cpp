#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll N=2e3,mod=1e9+7;
ll dp[N][N][2][2],k,dig;
string a,b;
ll rec(ll i=0,ll fact=0,ll f1=0,ll f2=0){
    if(i==a.size())return !fact;

    ll&ret=dp[i][fact][f1][f2];
    if(~ret)return ret;

    ret=0;
    ll mn=!f1?a[i]-'0':0,mx=!f2?b[i]-'0':9;
    for(int j=mn;j<=mx;j++){
        if((i%2&&j!=dig)||(i%2==0&&j==dig))continue;
        ret=(ret+rec(i+1,(fact*10+j)%k,!(!f1&&j==mn),!(!f2&&j==mx)))%mod;
    }
    return ret;
}
int main()
{
Ahmed_Sayed();
cin>>k>>dig>>a>>b;
while(a.size()<b.size())a='0'+a;
memset(dp,-1,sizeof dp);

cout<<rec();
}
