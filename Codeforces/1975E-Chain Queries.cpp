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


vector<ll>seg,v{0};
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

int timer;
vector<ll>in, out, x;
void dfs(int node = 1, int par = 0){
    in[node] = timer++;
    v.push_back(x[node]);

    for(auto i: adj[node])
        if(i != par)dfs(i, node);

    out[node] = timer++;

    v.push_back(-x[node]);
}

int main()
{
Ahmed_Sayed();
tt
int n, q;cin >> n >> q;

timer = 1;
in = out = x = vector<ll>(n + 1);
fill(adj, adj + n + 1, vector<int>());
v = {0};

for(int i = 1;i <= n;i++)cin >> x[i];
for(int i = 1;i < n;i++){
    int a, b;cin >> a >> b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

Lowest_CA lc(n);
lc.bul();
dfs();

seg = vector<ll>(v.size() * 4 + 5);
bul(1, 1, v.size() - 1);

set<pair<int,int>>s, s2, s3;
for(int i = 1;i <= n;i++)
    if(x[i])s.insert({lc.lvl[i], i}),s2.insert({out[i], i}),s3.insert({in[i], i});

while(q--){
    int o;cin >> o;

    up(1, 1, v.size()-1, in[o], x[o]? 0 : 1),
    up(1, 1, v.size()-1, out[o], x[o]? 0 : -1);

    x[o] = !x[o];

    if(x[o])
        s.insert({lc.lvl[o], o}),s2.insert({out[o], o}),s3.insert({in[o], o});
    else
        s.erase({lc.lvl[o], o}),s2.erase({out[o], o}),s3.erase({in[o], o});

    if(!s.size()){cout << "NO\n";continue;}
    if(s.size() == 1){cout << "YES\n";continue;}

    int a = s2.begin() -> second, b = s3.rbegin() -> second;
    if(a == b)a = s.begin() -> second,b = s3.rbegin() -> second;

    int lca = lc.LCA(a, b);

    ll sm = get(1,1,v.size()-1,in[lca],in[a])+
    get(1, 1, v.size()-1, in[lca], in[b]) -
    get(1, 1, v.size()-1, in[lca], in[lca]);

    cout << (sm == s.size() && sm == lc.distance(a, b) + 1? "YES" : "NO") << '\n';
}}
}