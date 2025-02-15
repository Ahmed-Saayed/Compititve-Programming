#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e4+5;
vector<pair<int,int>>adj[N];
vector<int>x;
 
struct HLD{
    vector<int>heavy,head,par,id,dep,sz,val;
    int nxt;
 
    HLD(int n):heavy(n+1),head(n+1),id(n+1),par(n+1),dep(n+1),val(n+1),sz(n+1,1){
        Dfs();
        nxt=1;
        head[1]=1;
        Flatten();
    }
 
    void Dfs(int node=1){
        for(auto [a,b]:adj[node]){
            if(a==par[node])continue;
 
            par[a]=node;
            dep[a]=dep[node]+1;
            val[a]=b;
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
 
        for(auto [a,b]:adj[node]){
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
 
int seg[N*4+5];
void bul(int node,int l,int r){
    if(l==r){
        seg[node]=x[l];
        return;
    }
 
    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);
 
    seg[node]=max(seg[node*2],seg[node*2+1]);
}
 
int get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef||lef>righ)return 0;
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
 
int main()
{
Ahmed_Sayed();
tt
int n;cin>>n;
 
fill(adj,adj+n+1,vector<pair<int,int>>());
fill(seg,seg+n*4+4,0);
x=vector<int>(n+1);
 
vector<pair<int,int>>edg;
for(int i=0;i<n-1;i++){
    int a,b,c;cin>>a>>b>>c,
 
    adj[a].push_back({b,c}),
    adj[b].push_back({a,c});
 
    edg.push_back({a,b});
}
 
HLD op(n);
 
 
for(int i=1;i<=n;i++)
    x[op.id[i]]=op.val[i];
 
for(auto&[a,b]:edg)
    if(b==op.par[a])swap(a,b);
 
bul(1,1,n);
 
string type;
while(cin>>type&&type!="DONE"){
 
    if(type=="CHANGE"){
        int id,val;cin>>id>>val;
 
        up(1,1,n,op.id[edg[id-1].second],val);
    }
    else{
        int u,v;cin>>u>>v;
        auto path=op.Path(u,v);
 
        int ans=0;
        for(auto[a,b]:path)
            ans=max(ans,get(1,1,n,a,b));
 
        cout<<ans<<'\n';
    }
}
}
}