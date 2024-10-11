#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll N=1e4,mod=1e9+7;
ll dp[N][100][2][2],k;
string a,b;
ll rec(ll i=0,ll sm=0,ll f1=0,ll f2=0){
    if(i==a.size())return !sm;

    ll&ret=dp[i][sm][f1][f2];
    if(~ret)return ret;

    ret=0;
    ll mn=!f1?a[i]-'0':0,mx=!f2?b[i]-'0':9;
    for(int j=mn;j<=mx;j++)
        ret=(ret+rec(i+1,(sm+j)%k,!(!f1&&j==mn),!(!f2&&j==mx)))%mod;

    return ret;
}
int main()
{
Ahmed_Sayed();
cin>>b>>k,a='1';
while(a.size()<b.size())a='0'+a;
memset(dp,-1,sizeof dp);

cout<<rec();
}
