#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e3+1;
vector<vector<int>>dis;
vector<pair<int,int>>adj[N];
void bfs(int root){
    queue<array<int,2>>q;
    q.push({0,root});

    while(q.size()){
        auto[cost,node]=q.front();q.pop();

        if(cost>dis[root][node])continue;
        dis[root][node]=cost;

        for(auto[a,b]:adj[node])
            if(cost+b<dis[root][a])
                dis[root][a]=cost+b,q.push({cost+b,a});
    }
}

int main()
{
Ahmed_Sayed();
int n,m,k;cin>>n>>m>>k;
dis=vector<vector<int>>(n+1,vector<int>(n+1,1e9));

vector<pair<int,int>>edges;
while(m--){
    int a,b,c;cin>>a>>b>>c;
    adj[a].push_back({b,c}),
    adj[b].push_back({a,c});

    edges.push_back({a,b});
}
vector<pair<int,int>>v(k);
for(auto&[a,b]:v)cin>>a>>b;

for(int i=1;i<=n;i++)bfs(i);

ll ans=1e18;
for(auto[a,b]:edges){
    ll sm=0;

    for(auto[u,v]:v){
        sm+=min({dis[u][a]+dis[b][v],dis[u][b]+dis[a][v],dis[u][v]});
        if(sm>ans)break;
    }
    ans=min(ans,sm);
}

cout<<ans;
}
