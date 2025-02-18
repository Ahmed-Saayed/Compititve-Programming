#include <bits/stdc++.h>			// COT2Spoj
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

struct st{
    ll par;
};

struct Lowest_CA{
    int lg;
    vector<vector<int>>adj;
    vector<vector<st>>anc;
    vector<int>lvl;

    Lowest_CA(int n){
        lg=27,
        anc=vector<vector<st>>(n+1,vector<st>(lg)),
        adj=vector<vector<int>>(n+1),
        lvl=vector<int>(n+1);
    }

    void bul(int node=1,int par=1){
        lvl[node]=lvl[par]+1;

        anc[node][0].par=par;
        for(int i=1;i<lg;i++){
            int p=anc[node][i-1].par;
            anc[node][i].par=anc[p][i-1].par;
        }

        for(auto i:adj[node]){
            if(i!=par)
                bul(i,node);
        }
    }

    int kth(int node,int k){
        for(int i=lg-1;i>=0;i--)
            if(k>>i&1)node=anc[node][i].par;

        return node;
    }

    int LCA(int u,int v){
        if(lvl[u]<lvl[v])swap(u,v);
        u=kth(u,lvl[u]-lvl[v]);

        if(u==v)return u;
        for(int i=lg-1;i>=0;i--){
            if(anc[u][i].par!=anc[v][i].par)
                u=anc[u][i].par,v=anc[v][i].par;
        }

        return anc[u][0].par;
    }
};

const int sqr=500,N=2e5+5;
vector<int>adj[N],v;

struct query{
    int l,r,idblk,idq,lca;

    query(){}

    query(int _l,int _r,int _idq,int lc){
        l=_l,r=_r,idq=_idq,idblk=l/sqr,lca=lc;
    }

    bool operator<(const query&q)const{
        if(idblk!=q.idblk)return idblk<q.idblk;

        return r<q.r;
    }
};

query qu[N];
int n,q,x[N],vis[(ll)1e6+6],cnt[(ll)1e6+6];
ll ans[N],ret;

void pross(int node){
    if(!vis[node]&&++cnt[x[node]]==1)ret++;
    if(vis[node]&&--cnt[x[node]]==0)ret--;

    vis[node]^=1;
}

int timer,in[N],out[N];
void MOsTree(){
    sort(qu,qu+q);

    int l=1,r=0;

    for(int i=0;i<q;i++){
        int a=v[qu[i].l],b=v[qu[i].r];

        while(l<qu[i].l)pross(v[l++]);
        while(l>qu[i].l)pross(v[--l]);

        while(r<qu[i].r)pross(v[++r]);
        while(r>qu[i].r)pross(v[r--]);

        int lca=qu[i].lca;

        if(lca!=a&&lca!=b)pross(lca);

        ans[qu[i].idq]=ret;

        if(lca!=a&&lca!=b)pross(lca);
    }

    for(int i=0;i<q;i++)
        cout<<ans[i]<<'\n';
}

void dfs(int node=1,int par=-1){
    in[node]=timer++;
    v.push_back(node);

    for(auto i:adj[node])
        if(i!=par)dfs(i,node);

    out[node]=timer++,
    v.push_back(node);
}

int main()
{
Ahmed_Sayed();
cin>>n>>q;
map<ll,ll>mp,mp2;
for(int i=1;i<=n;i++)cin>>x[i],mp[x[i]]++;

int o=0;
for(auto[a,b]:mp)mp2[a]=o++;
for(int i=1;i<=n;i++)x[i]=mp2[x[i]];

Lowest_CA lc(n);
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);

    lc.adj[a].push_back(b),
    lc.adj[b].push_back(a);
}

lc.bul();
dfs();

for(int i=0;i<q;i++){
    int l,r,lca;cin>>l>>r,lca=lc.LCA(l,r);

    if(in[l]>in[r])swap(l,r);

    if(lca!=l)
        qu[i]=query(out[l],in[r],i,lca);
    else
        qu[i]=query(in[l],in[r],i,lca);
}
MOsTree();
}
