#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,kk,x[50],dp[50][51],num;
ll rec(int i=0,int k=kk){
    if(i==n||!k)return i==n&&!k;

    ll&ret=dp[i][k],sm=0;
    if(~ret)return ret;

    ret=0;
    for(int j=i;j<n;j++)
        sm+=x[j],ret|=((sm&num)==num)&rec(j+1,k-1);

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n>>kk;
for(int i=0;i<n;i++)cin>>x[i];

for(ll i=55;~i;i--){
    memset(dp,-1,sizeof dp);
    num|=(1ll<<i);

    if(!rec())num-=(1ll<<i);
}

cout<<num;
}