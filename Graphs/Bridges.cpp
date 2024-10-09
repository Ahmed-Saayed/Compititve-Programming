#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5;
vector<ll>adj[N];
int in[N],vis[N],dn[N],low[N],id;
set<pair<int,int>>Bridge_Edges;

void bridges(int node,int par){
    vis[node]=1;
    low[node]=dn[node]=id++;

    for(auto i:adj[node]){
        if(par==i)continue;

        if(!vis[i]){
            bridges(i,node);
            low[node]=min(low[node],low[i]);
            if(low[i]>dn[node])Bridge_Edges.insert({node,i});
        }
        else low[node]=min(low[node],dn[i]);
    }
}

int main()
{
Ahmed_Sayed();
int n,m;cin>>n>>m;
while(m--){
    int u,v;cin>>u>>v,
    adj[u].push_back(v),
    adj[v].push_back(u);
}

bridges(1,0);
for(auto[u,v]:Bridge_Edges)
    cout<<u<<' '<<v<<'\n';
}