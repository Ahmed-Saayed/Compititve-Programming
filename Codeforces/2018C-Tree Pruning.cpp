#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=5e5+5;
vector<ll>adj[N],parent,dw,up,lvl;
vector<pair<ll,ll>>leaf;
int mxDepth;
int dfs(int node=1,int par=0,int depth=0){
    parent[node]=par,
    mxDepth=max(mxDepth,depth),
    lvl[node]=depth;

    ll ret=1;

    for(auto i:adj[node])
        if(par!=i)ret+=dfs(i,node,depth+1);

    dw[depth]+=ret-1;
    if(ret==1)leaf.push_back({depth,node});

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
int n;cin>>n;

mxDepth=0,
leaf.clear(),
parent=dw=up=lvl=vector<ll>(n+1),
fill(adj,adj+n+1,vector<ll>());

for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
dfs();

int vis[n+1]{};vis[1]=1;
sort(all(leaf)),reverse(all(leaf));
for(auto [a,b]:leaf){
    ll node=b,c=0;

    while(!vis[node])
        c++,
        vis[node]=1,
        node=parent[node];

    up[a]+=c;
}

ll ans=1e18,sm=0;
for(int i=0;i<=mxDepth;i++){
    ans=min(ans,sm+dw[i]),
    sm+=up[i];
}

cout<<ans<<'\n';}
}