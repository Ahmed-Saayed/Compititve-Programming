#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll getbit(ll n,ll j){return(n>>j)&1;}#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

bool ok(int i,int j,int n,int m){
    return (i>0&&j>0&&i<=n&&j<=m);
}

int main()
{
Ahmed_Sayed();
ll n,m,x,s1,s2;cin>>n>>m>>x>>s1>>s2;
ll v[n+1][m+1],dx[4]{1,-1,0,0},dy[4]{0,0,1,-1};
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)cin>>v[i][j];

double o=1.0/x;
vector<vector<bool>>vis(n+1,vector<bool>(m+1));
vis[s1][s2]=1;

ll ans=v[s1][s2];
priority_queue<array<ll,3>,vector<array<ll,3>>,greater<>>pq;
for(int k=0;k<4;k++){
    int a=dx[k]+s1,b=dy[k]+s2;

    if(ok(a,b,n,m)&&!vis[a][b])
        vis[a][b]=1,pq.push({v[a][b],a,b});
}

while(pq.size()){
    auto[val,i,j]=pq.top();pq.pop();

    if(val<(ll)(ans*o)+((ll)(ans*o)!=(ans*o)))
        ans+=val;
    else
        continue;

    for(int k=0;k<4;k++){
        int a=dx[k]+i,b=dy[k]+j;

        if(ok(a,b,n,m)&&!vis[a][b])
            vis[a][b]=1,pq.push({v[a][b],a,b});
    }
}

cout<<ans;
}

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
