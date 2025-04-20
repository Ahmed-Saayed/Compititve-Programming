#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
 
const int N=2e5+5,lg=27;
int n,anc[N][lg],lvl[N];
vector<ll>adj[N];
 
void bul(int node=1,int par=1){
    lvl[node]=lvl[par]+1;
 
    anc[node][0]=par;
    for(int i=1;i<lg;i++){
        int p=anc[node][i-1];
        anc[node][i]=anc[p][i-1];
    }
 
    for(auto i:adj[node]){
        if(i!=par)
            bul(i,node);
 
    }
}
 
int kth(int node,int k){
    for(int i=lg-1;i>=0;i--)
        if(k>>i&1)node=anc[node][i];
 
    return node;
}
 
int LCA(int u,int v){
    if(lvl[u]<lvl[v])swap(u,v);
    u=kth(u,lvl[u]-lvl[v]);
 
    if(u==v)return u;
    for(int i=lg-1;i>=0;i--){
        if(anc[u][i]!=anc[v][i])
            u=anc[u][i],v=anc[v][i];
    }
 
    return anc[u][0];
}
 
ll pre[N],ans[N];
ll dfs(int node=1,int par=0){
    ll ret=pre[node];
 
    for(auto i:adj[node])
        if(i!=par)ret+=dfs(i,node);
 
    ans[node]=ret;
    return ret;
}
 
int main()
{
Ahmed_Sayed();
int n,m;cin>>n>>m;
vector<int>lca;
for(int i=0;i<n-1;i++){
    ll a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
bul();
 
for(int i=0;i<m;i++){
    ll a,b,lc;cin>>a>>b,lc=LCA(a,b);
    lca.push_back(lc),
 
    pre[a]++,pre[b]++,pre[lc]-=2;
}
 
dfs();
for(auto i:lca)ans[i]++;
 
 
for(int i=1;i<=n;i++)
    cout<<ans[i]<<' ';
}
