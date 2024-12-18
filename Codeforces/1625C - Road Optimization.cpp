#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll n,l,k,x[501],y[501],dp[501][501];
ll rec(ll i=0,ll o=k){
    if(i==n)return 0;

    ll &ret=dp[i][o];
    if(~ret)return ret;

    ret=1e18;

    for(int j=0;j<=o&&i+j+1<=n;j++){
        ret=min(ret,(x[i+j+1]-x[i])*y[i]+rec(i+j+1,o-j));
    }

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n>>l>>k;
for(int i=0;i<n;i++)cin>>x[i];
for(int i=0;i<n;i++)cin>>y[i];
x[n]=l;

memset(dp,-1,sizeof dp);

cout<<rec();
}