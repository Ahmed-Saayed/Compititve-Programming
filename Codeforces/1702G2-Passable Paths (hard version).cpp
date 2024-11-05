#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N = 2e5 + 5;
vector<int>adj[N];

struct st{
    ll par;
};
struct Lowest_CA{
    int lg;
    vector<vector<st>>anc;
    vector<int>lvl;

    Lowest_CA(int n){
        lg = 27,
        anc = vector<vector<st>>(n + 1,vector<st>(lg)),
        lvl = vector<int>(n + 1);
    }

    void bul(int node = 1,int par = 1){
        lvl[node] = lvl[par] + 1;

        anc[node][0].par = par;
        for(int i = 1 ;i < lg; i++){
            int p = anc[node][i - 1].par;
            anc[node][i].par = anc[p][i - 1].par;
        }

        for(auto i: adj[node]){
            if(i != par)
                bul(i, node);
        }
    }

    int kth(int node, int k){
        for(int i = lg - 1;i >= 0;i--)
            if(k >> i & 1)node = anc[node][i].par;

        return node;
    }

    int LCA(int u, int v){
        if(lvl[u] < lvl[v])swap(u, v);
        u = kth(u, lvl[u] - lvl[v]);

        if(u == v)return u;
        for(int i = lg - 1; i >= 0;i--){
            if(anc[u][i].par != anc[v][i].par)
                u = anc[u][i].par, v = anc[v][i].par;
        }

        return anc[u][0].par;
    }

    int distance(int u, int v){
        return lvl[u] + lvl[v] - lvl[LCA(u, v)] * 2;
    }
};

int seg[N*8+5];
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


int in[N],out[N],timer=1;
void dfs(int node = 1, int par = 0){
    in[node] = timer++;

    for(auto i:adj[node])
        if(par != i)dfs(i, node);

    out[node] = timer++;
}

int main()
{
Ahmed_Sayed();
int n;cin >> n;
for(int i = 0;i < n - 1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

dfs();
Lowest_CA lc(n);
lc.bul();

int q;cin >> q;
while(q--){
    int sz;cin >> sz;
    set<pair<int,int>>s1, s2, s3;
    while(sz--){
        int o;cin >> o,

        up(1 ,1 ,n * 2 ,in[o] ,1),up(1 ,1, n * 2 ,out[o] ,-1),
        s1.insert({in[o], o}),s2.insert({out[o], o}),s3.insert({lc.lvl[o], o});
    }

    int a = s2.begin()->second,b = s1.rbegin()->second;
    if(a == b)
        a = s3.begin()->second,b = s3.rbegin()->second;

    int lca = lc.LCA(a, b), sm = get(1 ,1 ,n * 2, in[lca], in[a])
     + get(1, 1,n * 2, in[lca], in[b])
     - get(1, 1,n * 2, in[lca], in[lca]);

    cout<<(sm == s1.size()?"YES":"NO")<<'\n';

    for(auto [a,b]:s1)
        up(1, 1, n * 2 ,in[b] ,0),up(1, 1, n * 2 ,out[b] ,0);
}
}
