#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

const int N=3e5+5,lg=27;
int n,lvl[N],ans;
vector<pair<int,int>>adj[N];

struct st{
    int an,mx;
};

st anc[N][lg];

void bul(int node=1,int par=1,int val=0){
    lvl[node]=lvl[par]+1;

    anc[node][0].an=par,
    anc[node][0].mx=val;

    for(int i=1;i<lg;i++){
        int p=anc[node][i-1].an;
        anc[node][i].an=anc[p][i-1].an;
        anc[node][i].mx=max(anc[node][i-1].mx,anc[p][i-1].mx);
    }

    for(auto [a,b]:adj[node]){
        if(a!=par)
            bul(a,node,b);
    }
}

int kth(int node,int k){
    for(int i=lg-1;i>=0;i--)
        if(k>>i&1)
        ans=max(ans,anc[node][i].mx),
        node=anc[node][i].an;

    return node;
}

int LCA(int u,int v){
    if(lvl[u]<lvl[v])swap(u,v);
    u=kth(u,lvl[u]-lvl[v]);

    if(u==v)return u;
    for(int i=lg-1;i>=0;i--){
        if(anc[u][i].an!=anc[v][i].an)
            u=anc[u][i].an,v=anc[v][i].an;
    }

    return anc[u][0].an;
}

struct DSU{
vector<ll>par,sz;
ll sm,edges;

DSU(ll n){
sm=0,edges=n;
par=sz=vector<ll>(n+1);
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
    if(sz[x]>=sz[y])sz[x]+=sz[y],par[y]=x;
    else sz[y]+=sz[x],par[x]=y;
    return 1;
}
};

int main()
{
Ahmed_Sayed();
int n,m;cin>>n>>m;
DSU op(n);

vector<array<ll,3>>v(m),v2;

for(auto&[a,b,c]:v)cin>>b>>c>>a;
v2=v;
sort(all(v));

for(auto&[a,b,c]:v){
    if(op.merge(b,c,a))
        adj[b].push_back({c,a}),
        adj[c].push_back({b,a});
}
bul();

for(auto[a,b,c]:v2){
    int lca;lca=LCA(b,c);

    ans=0;
    kth(c,lvl[c]-lvl[lca]),
    kth(b,lvl[b]-lvl[lca]);

    cout<<op.sm-ans+a<<'\n';
}
}