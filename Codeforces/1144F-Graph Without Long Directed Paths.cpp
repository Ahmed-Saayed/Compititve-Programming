#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
vector<vector<ll>>adj;
vector<ll>vis;
bool dfs(ll node,ll o=0){
    vis[node]=o;
    ll ret=1;
    for(auto i:adj[node]){
        if(vis[i]==-1)ret&=dfs(i,!o);
        if(vis[i]==o)ret=0;
    }
    return ret;
}
int main()
{
Ahmed_Sayed();
ll n,m;cin>>n>>m;
adj=vector<vector<ll>>(n+1,vector<ll>());
vis=vector<ll>(n+1,-1);
vector<pair<ll,ll>>v(m);

for(auto &[a,b]:v)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);

if(!dfs(1))cout<<"NO";
else{
        map<pair<ll,ll>,ll>mp;
    for(int i=1;i<=n;i++){
        for(auto j:adj[i])if(vis[i]&&!vis[j])mp[{i,j}]++;
    }
    cout<<"YES\n";
    for(auto i:v)cout<<mp[i];
}

}
