#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,x[20][20];
vector<vector<ll>>dp;
ll rec(ll mask=0,ll i=0){
    if(i==n)return 1;

    ll &ret=dp[i][mask];
    if(~ret)return ret;

    ret=0;
    for(int o=0;o<n;o++)if(!((mask>>o)&1)&&x[i][o])ret=ret+rec(mask|(1<<o),i+1);
    return ret;
}

int main()
{
Ahmed_Sayed();
tt
cin>>n;
for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>x[i][j];
dp=vector<vector<ll>>(n,vector<ll>((1<<n)-1,-1));
cout<<rec();
nn;}
}
