#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,m,x[20][2],dp[1<<16][20][2];
ll rec(ll mask=0,ll prev=0,ll o=1,ll sm=0){
    if(sm==n)return x[prev][o]==x[1][0];

    ll&ret=dp[mask][prev][o];
    if(~ret)return ret;

    ret=0;
    for(int i=2;i<m+2;i++){
        if((mask>>i)&1)continue;
        if(x[i][0]==x[prev][o])ret+=rec(mask|(1<<i),i,1,sm+1);
        if(x[i][1]==x[prev][o])ret+=rec(mask|(1<<i),i,0,sm+1);
    }
    return ret;
}

int main()
{
Ahmed_Sayed();
while(cin>>n&&n){
        cin>>m;
for(int i=0;i<m+2;i++)cin>>x[i][0]>>x[i][1];
memset(dp,-1,sizeof dp);
cout<<(rec()?"YES":"NO");
nn;}
}
