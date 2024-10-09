#include <bits/stdc++.h>
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
    //,mx,mn,sm;
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

int main()
{
Ahmed_Sayed();
int n;cin>>n;
Lowest_CA lca(n);

for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v,
    lca.adj[u].push_back(v),
    lca.adj[v].push_back(u);
}
lca.bul();

int q;cin>>q;
while(q--){
    int u,v;cin>>u>>v;
    cout<<lca.LCA(u,v)<<'\n';
}
}
