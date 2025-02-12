#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll n,m,k,cost[301][301],dp[301][301];
ll rec(int i=1,int o=k){
    if(i>n)return !o?0:1e18;

    ll&ret=dp[i][o];
    if(~ret)return ret;

    ret=rec(i+1,o);

    for(int j=i;j<=n&&j-i+1<=o;j++)
        ret=min(ret,cost[i][j]+rec(j+1,o-(j-i+1)));

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n>>m>>k;

for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)cost[i][j]=1e18,dp[i][j]=-1;

while(m--){
    ll a,b,c;cin>>a>>b>>c;
    for(int i=a;i<=b;i++)cost[i][b]=min(cost[i][b],c);
}

cout<<(rec()>=1e18?-1:rec());
}