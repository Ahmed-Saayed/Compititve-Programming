#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;        // Batching (Buffer)  Idea

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e5+5,sq=400;
vector<int>adj[N];
struct st{
    ll par;
    //,mx,mn,sm;
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
            //anc[node][i].sm=anc[node][i-1].sm+anc[p][i-1].sm;
        }

        for(auto i:adj[node]){
            if(i!=par)
                bul(i,node);
        }
    }

    int kth(int node,int k){
        for(int i=lg-1;i>=0;i--)
            //ans=max(ans,anc[node][i].mx),
            //sm=max(ans,anc[node][i].sm),
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


int main()
{
Ahmed_Sayed();
int n,m;cin>>n>>m;
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

Lowest_CA lc(n);
lc.bul();

vector<int>dis(n+1,1e9);
deque<pair<int,int>>dq;
dq.push_back({0,1});

while(m--){
    int o,u;cin>>o>>u;

    if(m%sq==0)
        while(dq.size()){
            auto[cost,node]=dq.front();dq.pop_front();

            if(cost>dis[node])continue;
            dis[node]=cost;

            for(auto i:adj[node])
                if(cost+1<dis[i])dis[i]=cost+1,dq.push_back({cost+1,i});
        }

    if(o==1)
        dq.push_back({0,u});

    else{
        int ans=dis[u];
        for(auto [a,b]:dq)
            ans=min(ans,lc.distance(u,b));

        cout<<ans<<'\n';
    }
}
}
