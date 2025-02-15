#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e5+5;
vector<int>adj[N];

struct HLD{
    vector<int>heavy,head,par,id,dep,sz,val;
    int nxt;


    HLD(){}
    HLD(int n):heavy(n+1),head(n+1),id(n+1),par(n+1),dep(n+1),val(n+1),sz(n+1,1){
        Dfs();
        nxt=1;
        head[1]=1;
        Flatten();
    }

    void Dfs(int node=1){
        for(auto a:adj[node]){
            if(a==par[node])continue;

            par[a]=node;
            dep[a]=dep[node]+1;
            Dfs(a);
            sz[node]+=sz[a];

            if(!heavy[node]||sz[a]>sz[heavy[node]])heavy[node]=a;
        }
    }

    void Flatten(int node=1){
        id[node]=nxt++;

        if(heavy[node])
            head[heavy[node]]=head[node],
            Flatten(heavy[node]);

        for(auto a:adj[node]){
            if(a==par[node]||a==heavy[node])continue;

            head[a]=a;
            Flatten(a);
        }
    }

    vector<pair<int,int>>Path(int u,int v){
        vector<pair<int,int>>ret;

        while(1){
            if(head[u]==head[v]){
                if(dep[u]>dep[v])swap(u,v);

                ret.push_back({id[u]+1,id[v]});
                return ret;
            }

            if(dep[head[u]]>dep[head[v]])swap(u,v);
            ret.push_back({id[head[v]],id[v]});
            v=par[head[v]];
        }
    }

};

struct st{
    ll par;
};

struct Lowest_CA{
    int lg;
    vector<vector<st>>anc;
    vector<int>lvl;

    Lowest_CA(){}
    Lowest_CA(int n){
        lg=27,
        anc=vector<vector<st>>(n+1,vector<st>(lg)),
        lvl=vector<int>(n+1);

        bul();
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

    int distance(int u,int v){
        return lvl[u]+lvl[v]-lvl[LCA(u,v)]*2;
    }
};

int seg[N*4+1];
int get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return max(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
}

void up(int node,int l,int r,int id,int val){
    if(l>id||r<id)return;
    if(l==r){
        seg[node]=val;
        return;
    }

    int m=l+r>>1;
    up(node*2,l,m,id,val),
    up(node*2+1,m+1,r,id,val);

    seg[node]=max(seg[node*2],seg[node*2+1]);
}

Lowest_CA lc;
HLD hd;
bool ok(int node,int md,int n){
    int lca=lc.kth(node,md);

    auto path=hd.Path(1,lca);

    int ans=0;
    for(auto[a,b]:path)
        ans=max(ans,get(1,1,n,a,b));

    return ans;
}

int main()
{
Ahmed_Sayed();
int n,q;cin>>n>>q;

int nodes[n+1]{};
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

lc=Lowest_CA(n);
hd=HLD(n);

while(q--){
    int type,node;cin>>type>>node;
    if(!type){
        nodes[node]=!nodes[node];
        up(1,1,n,hd.id[node],nodes[node]);
    }
    else{
        int l=1,r=hd.dep[node]+2,md;
        while(l<=r){
            md=l+r>>1;

            (ok(node,md,n)?l=md+1:r=md-1);
        }

        cout<<(ok(node,r,n)?lc.kth(node,r):-1)<<'\n';
    }
}
}
