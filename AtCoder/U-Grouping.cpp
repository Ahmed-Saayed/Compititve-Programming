#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll getbit(ll n,ll j){return(n>>j)&1;}
ll mxmask[1<<16],dp[1<<16];

ll rec(ll mask){
    if(!mask)return 0;

     ll &ret=dp[mask];
     if(~ret)return ret;

     ret=0;
     for(int i=mask;i;i=((i-1)&mask))ret=max(ret,mxmask[i]+rec(mask^i));
     return ret;
}
int main()
{
Ahmed_Sayed();
ll n;cin>>n;
ll x[n][n];
for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>x[i][j];
memset(dp,-1,sizeof dp);

for(int i=0;i<1<<n;i++){
    for(int j=0;j<n;j++)
        for(int k=j+1;k<n;k++)if(getbit(i,k)&&getbit(i,j))mxmask[i]+=x[j][k];
}
cout<<rec((1<<n)-1);
}
