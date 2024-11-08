#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll N=1001,mod=998244353;
vector<int>adj[N],adj2[N],vis,vis2;

void dfs(int node){
    vis[node]=1;

    for(auto i:adj[node])
        if(!vis[i])dfs(i);
}

int dfs2(int node){
    vis2[node]=1;
    
    int ret=1;
    for(auto i:adj2[node])
        if(!vis2[i])ret+=dfs2(i);

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
int n;cin>>n;

vis=vis2=vector<int>(n+1),
fill(adj,adj+n+1,vector<int>()),
fill(adj2,adj2+n+1,vector<int>());

int x[n*2];
for(int i=0;i<n*2;i++)cin>>x[i];

for(int i=0;i<n*2;i++){
    if(!vis[x[i]]){
        vis[x[i]]=1;

        for(int j=i+1;x[j]!=x[i];j++)
            adj[x[i]].push_back(x[j]),adj2[x[j]].push_back(x[i]);
    }
}

vis=vector<int>(n+1);

ll ans=0,sm=1;
for(int i=0;i<n*2;i++){
    if(!vis[x[i]])
        ans++,dfs(x[i]),sm=(sm*2*dfs2(x[i]))%mod;
}

cout<<ans<<' '<<sm<<'\n';}
}