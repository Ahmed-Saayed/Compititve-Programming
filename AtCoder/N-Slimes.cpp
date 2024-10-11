#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll n,x[401],dp[401][401];
ll rec(int i=1,int j=n){
    if(j-i==1)return x[j]-x[i-1];
    if(i==j)return 0;

    ll&ret=dp[i][j];
    if(~ret)return ret;

    ret=1e18;
    for(int k=i;k<=j;k++)ret=min(ret,x[j]-x[i-1]+rec(i,k)+rec(k+1,j));
    return ret;
}
int main()
{
Ahmed_Sayed();
cin>>n;
memset(dp,-1,sizeof dp);

for(int i=1;i<=n;i++)cin>>x[i],x[i]+=x[i-1];
cout<<rec();
}
//