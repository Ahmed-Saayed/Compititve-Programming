#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e5+5;
vector<pair<ll,ll>>adj[N];
priority_queue<pair<ll,int>>pq;
ll n,sum,sz[N],val[N];
int dfs(int node=1,int par=0,ll sm=0,ll value=0){
    int ret=0,c=0;
    for(auto [a,b]:adj[node])
        if(a!=par)ret+=dfs(a,node,sm+b,b),c++;

    if(!c)
        ret=1,sum+=sm;

    val[node]=value;
    pq.push({ret*(value-value/2),node});

    return sz[node]=ret;
}

int main()
{
Ahmed_Sayed();
tt
ll s;cin>>n>>s;

while(pq.size())pq.pop();
fill(adj,adj+n+1,vector<pair<ll,ll>>()),
sum=0;

for(int i=0;i<n-1;i++){
    ll a,b,c;cin>>a>>b>>c,
    adj[a].push_back({b,c}),
    adj[b].push_back({a,c});
}
dfs();

ll ans=0;
while(sum>s){
    auto[cost,node]=pq.top();pq.pop();

    sum-=cost,
    val[node]/=2,
    pq.push({sz[node]*(val[node]-val[node]/2),node});

    ans++;
}

cout<<ans<<'\n';}
}
