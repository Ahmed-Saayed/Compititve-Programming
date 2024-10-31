#include <bits/stdc++.h>
#define ll long long
#define int long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N = 2e5 + 5;
vector<ll>adj[N],seg,v{0};

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



void bul(int node, int l, int r){
    if(l == r){
        seg[node] = v[l];
        return;
    }

    int m = l + r >> 1;
    bul(node * 2, l, m),
    bul(node * 2 + 1, m + 1, r);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll get(int node, int l, int r, int lef, int righ){
    if(l > righ || r < lef)return 0;
    if(l >= lef && r <= righ)return seg[node];

    int m = l + r >> 1;
    return get(node * 2, l, m, lef, righ) + get(node * 2 + 1, m + 1, r, lef, righ);
}

void up(int node,int l, int r, int id, int val){
    if(l > id || r < id)return;
    if(l == r){
        seg[node] = val;
        return;
    }

    int m = l + r >> 1;
    up(node * 2, l, m, id, val),
    up(node * 2 + 1, m + 1, r, id, val);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int timer=1;
int in[N],out[N];
map<pair<int,int>,ll>mp;
void dfs(int node = 1, int par = 0){
    in[node] = timer++;
    v.push_back(mp[{par,node}]);

    for(auto i: adj[node])
        if(i != par)dfs(i, node);

    out[node] = timer++;

    v.push_back(-mp[{par,node}]);
}

int32_t main()
{
Ahmed_Sayed();
int n, q;cin >> n;

vector<pair<int,int>>edges;
for(int i = 1;i < n;i++){
    int a, b, val;cin >> a >> b >> val,
    adj[a].push_back(b),
    adj[b].push_back(a),
    edges.push_back({a,b});

    mp[{a,b}] = mp[{b,a}] = val;
}
Lowest_CA lc(n);
lc.bul();
dfs();
seg=vector<ll>(v.size()*4+5);
bul(1,1,v.size()-1);


for(auto&[a,b]:edges)
    if(lc.lvl[b]<lc.lvl[a])swap(a,b);

cin >> q;
while(q--){
    int o;cin >> o;
    if(o==1){
        int id, val;cin >> id >> val;

        up(1,1,v.size()-1, in[edges[id - 1].second], val);
        up(1,1,v.size()-1, out[edges[id - 1].second], -val);
    }
    else{
        int a,b,lca;cin>>a>>b,lca=lc.LCA(a,b);


        cout << get(1,1,v.size()-1,in[lca],in[b]) + get(1,1,v.size()-1,in[lca],in[a]) - get(1,1,v.size()-1,in[lca],in[lca]) * 2 << '\n';
    }
}
}
