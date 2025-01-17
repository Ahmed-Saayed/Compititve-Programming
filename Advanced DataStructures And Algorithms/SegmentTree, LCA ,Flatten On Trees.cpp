#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){		//SPOJ - QTREE2
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e5+5;
vector<pair<int,int>>adj[N];
struct st{
    ll par;
};
 
struct Lowest_CA{
    int lg;
    vector<vector<st>>anc;
    vector<int>lvl;
 
    Lowest_CA(int n){
        lg=27,
        anc=vector<vector<st>>(n+1,vector<st>(lg)),
        lvl=vector<int>(n+1);
    }
 
    void bul(int node=1,int par=1){
        lvl[node]=lvl[par]+1;
 
        anc[node][0].par=par;
        for(int i=1;i<lg;i++){
            int p=anc[node][i-1].par;
            anc[node][i].par=anc[p][i-1].par;
        }
 
        for(auto [a,b]:adj[node]){
            if(a!=par)
                bul(a,node);
        }
    }
 
    int kth(int node,int k){
        for(int i=lg-1;i>=0;i--)
            if(k>>i&1)
                node=anc[node][i].par;
 
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
 
 
vector<ll>seg,v;
void bul(int node,int l,int r){
    if(l==r){
        seg[node]=v[l];
        return;
    }
 
    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);
 
    seg[node]=seg[node*2]+seg[node*2+1];
}
 
ll get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node];
 
    int m=l+r>>1;
    return get(node*2,l,m,lef,righ)+get(node*2+1,m+1,r,lef,righ);
}
 
int timer=1,in[N],out[N];
map<pair<int,int>,int>mp;
void dfs(int node=1,int par=-1){
    in[node]=timer++;
    v.push_back(mp[{node,par}]);
 
    for(auto [a,b]:adj[node])
        if(a!=par)dfs(a,node);
 
    out[node]=timer++,
    v.push_back(-mp[{node,par}]);
}
 
int main()
{
Ahmed_Sayed();
tt
int n;cin>>n;
 
timer=1,
fill(adj,adj+n+1,vector<pair<int,int>>()),
v=vector<ll>(1),
mp.clear();
 
for(int i=0;i<n-1;i++){
    int a,b,c;cin>>a>>b>>c,
    mp[{a,b}]=mp[{b,a}]=c,
 
    adj[a].push_back({b,c}),
    adj[b].push_back({a,c});
}
 
dfs();
seg=vector<ll>(v.size()*4+5),
bul(1,1,v.size()-1);
 
Lowest_CA op(n+1);
op.bul();
 
string q;
while(cin>>q&&q!="DONE"){
    if(q=="KTH"){
        int a,b,c;cin>>a>>b>>c;
        int lca=op.LCA(a,b);
 
        if(op.distance(a,lca)+1>=c)
            cout<<op.kth(a,c-1);
        else
            c-=op.distance(a,lca)+1,
            cout<<op.kth(b,op.distance(b,lca)-c);
    }
    else{
        int a,b,lca;cin>>a>>b,lca=op.LCA(a,b);
 
        cout<<get(1,1,v.size()-1,in[lca]+1,in[a])+get(1,1,v.size()-1,in[lca]+1,in[b]);
    }
 
    nn;
}
nn;}
}