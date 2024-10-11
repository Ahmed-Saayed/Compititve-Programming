#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,k,x[100],dp[(ll)1e5+1];
ll rec(ll win=k){
    ll &ret=dp[win];
    if(~ret)return ret;

    ret=0;
    for(int i=0;i<n;i++)
        if(win-x[i]>=0)ret|=!rec(win-x[i]);

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n>>k;
memset(dp,-1,sizeof dp);
for(int i=0;i<n;i++)cin>>x[i];
cout<<(rec()?"First":"Second");//
}
