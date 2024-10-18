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
int ans;
vector<int>adj[N],dis;
void dfs(int node,int par,int dep=0){
    if(dep>=dis[node]||dep>ans)return;
    dis[node]=dep;

    for(auto i:adj[node])
        if(i!=par)dfs(i,node,dep+1);
}

int main()
{
Ahmed_Sayed();
tt
int n,o;cin>>n>>o,ans=1e9;

dis=vector<int>(n+1,1e9);
fill(adj,adj+n+1,vector<int>());

int x[n-1];
for(auto&i:x)cin>>i;
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

dfs(o,0,0);

for(auto i:x){
    ans=min(ans,dis[i]);
    cout<<ans<<' ';

    dfs(i,0,0);
}
nn;}
}