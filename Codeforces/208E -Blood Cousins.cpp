#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

const int N=2e5;
vector<bool>vis;
vector<int>adj[N];
struct st{
    ll par;
    //,mx,mn,sm;
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
    }

    void bul(int node=1,int par=1){
        lvl[node]=lvl[par]+1,
        vis[node] = 1;

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
Lowest_CA op;
int in[N],out[N],timer=0;
vector<int>v[N];
void dfs(int node,int par){
    vis[node]=1,
    in[node]=timer++,
    v[op.lvl[node]].push_back(in[node]);

    for(auto i:adj[node])
        if(i!=par)dfs(i,node);

    out[node]=timer++;
}

int main()
{
Ahmed_Sayed();
int n;cin>>n;
for(int i=1;i<=n;i++){
    int a;cin>>a;
    if(a)adj[a].push_back(i);
}
int q;cin>>q;

op=Lowest_CA(n+1);
vis=vector<bool>(n+1);
for(int i=1;i<=n;i++)
    if(!vis[i])op.bul(i,0);

vis=vector<bool>(n+1);
for(int i=1;i<=n;i++)
    if(!vis[i])dfs(i,0);

while(q--){
    int node,p,lca;
    cin>>node>>p,lca=op.kth(node,p);;

    cout<<max(int(upper_bound(all(v[op.lvl[node]]),out[lca])-
                  lower_bound(all(v[op.lvl[node]]),in[lca]))-1,0)<<' ';

}

}
