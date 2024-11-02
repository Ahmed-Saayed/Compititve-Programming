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
vector<int>adj[N];

ll o,mx,dis[N],MxPath[N];
void dfs(int node=1,int par=0,int d=0){
    if(d>mx)mx=d,o=node;

    dis[node]=dis[par]+1;
    for(auto i:adj[node])
        if(i!=par)dfs(i,node,d+1);
}

void dfs2(int node,int par=0,int d=0){
    MxPath[node]=max(MxPath[node],(ll)d);
    for(auto i:adj[node])
        if(i!=par)dfs2(i,node,d+1);
}

int main()
{
Ahmed_Sayed();
tt
int n,k,c;cin>>n>>k>>c;

fill(adj,adj+n+1,vector<int>()),
fill(dis,dis+n+1,0),
fill(MxPath,MxPath+n+1,0),
mx=0;

for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

dfs(),
dfs2(o);

ll ans=0;
for(int i=1;i<=n;i++)
    ans=max(ans,MxPath[i]*k-(dis[i]-1)*c);

cout<<ans<<'\n';}
}