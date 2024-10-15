#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

struct DSU{
vector<ll>par,sz,path;
ll sm,edges;

DSU(ll n){
sm=0,edges=n;
par=sz=path=vector<ll>(n+1);
for(int i=0;i<=n;i++)par[i]=i,sz[i]=1;
}

ll findlead(ll n){
    if(par[n]==n)return n;
    return par[n]=findlead(par[n]);
}


bool merge(ll x,ll y,ll c){
    x=findlead(x),y=findlead(y);
    if(x==y)return 0;

    sm+=c,edges--;

    if(sz[x]<sz[y])swap(x,y);

    sz[x]+=sz[y],
    path[x]=max({path[x],path[y],(path[x]+1)/2+(path[y]+1)/2+1})
    ,par[y]=x;

    return 1;
}

};

vector<ll>vis;

ll mx=0,o;
vector<ll>adj[(ll)3e5+1];
void dfs(ll node,ll par,ll cnt=0){
    if(cnt>mx)mx=cnt,o=node;
    vis[node]=1;

    for(auto i:adj[node])
        if(par!=i)dfs(i,node,cnt+1);
}

int main()
{
Ahmed_Sayed();
ll n,m,q;cin>>n>>m>>q;
DSU op(n);
while(m--){
    ll a,b;cin>>a>>b;
    op.merge(a,b,0);
    adj[a].push_back(b),adj[b].push_back(a);
}

vis=vector<ll>(n+1);
for(int i=1;i<=n;i++){
    if(!vis[i]){
        mx=-1;
        dfs(i,-1);
        mx=-1;
        dfs(o,-1);
        op.path[op.findlead(i)]=mx;
    }
}

while(q--){
    ll x,a,b;cin>>x>>a,x--;
    if(!x)
        cout<<op.path[op.findlead(a)]<<'\n';
    else
        cin>>b,op.merge(a,b,0);
}
}