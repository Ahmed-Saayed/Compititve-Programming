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
int vis[N],dn[N],low[N],id;
vector<int>adj[N];
set<int>arc;
void articulation_points(int node,int par){
    vis[node]=1;
    low[node]=dn[node]=id++;
    int c=0;

    for(auto i:adj[node]){
        if(par==i)continue;

        if(!vis[i]){
            articulation_points(i,node);
            low[node]=min(low[node],low[i]);
            if(low[i]>=dn[node]&&~par)arc.insert(node);
        c++;
        }
        else low[node]=min(low[node],dn[i]);
    }

    if(par==-1&&c>1)arc.insert(node);
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

for(int i=1;i<=n;i++)
    if(!vis[i])articulation_points(i,-1);

for(auto i:arc)cout<<i<<' ';
}