#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll N=2e5+5;
ll n,pre[3][N],dp[N][3];
ll rec(int i=1,int o=0){
    if(i>n||o==3)return i>n?0:1e9;

    ll&ret=dp[i][o];
    if(~ret)return ret;

    ret=rec(i,o+1);

    return ret=min(ret,!pre[o][i]+rec(i+1,o));
}

int main()
{
Ahmed_Sayed();
ll k1,k2,k3;cin>>k1>>k2>>k3;
n=k1+k2+k3;
memset(dp,-1,sizeof dp);

for(int i=0;i<k1;i++){
    ll o;cin>>o,pre[0][o]++;
}

for(int i=0;i<k2;i++){
    ll o;cin>>o,pre[1][o]++;
}

for(int i=0;i<k3;i++){
    ll o;cin>>o,pre[2][o]++;
}

cout<<rec();
}
