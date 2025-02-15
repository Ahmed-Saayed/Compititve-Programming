#include <bits/stdc++.h>
#define ll long long
#define int long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N = 2e5 + 5;
vector<ll>adj[N],seg,v{0};
 
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
int in[N],out[N],x[N];
void dfs(int node = 1, int par = 0){
    in[node] = timer++;
    v.push_back(x[node]);
 
    for(auto i: adj[node])
        if(i != par)dfs(i, node);
 
    out[node] = timer++;
    v.push_back(-x[node]);
}
 
int32_t main()
{
Ahmed_Sayed();
int n, q;cin >> n >>q;
for(int i=1;i<=n;i++)cin>>x[i];
 
for(int i = 1;i < n;i++){
    int a, b;cin >> a >> b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
 
dfs();
seg=vector<ll>(v.size()*4+5);
bul(1,1,v.size()-1);
 
while(q--){
    int o;cin >> o;
    if(o==1){
        int id, val;cin >> id >> val;
 
        up(1,1,v.size()-1, in[id], val);
        up(1,1,v.size()-1, out[id], -val);
    }
    else{
        int a;cin>>a;
 
        cout << get(1,1,v.size()-1,in[1],in[a])  << '\n';
    }
}
}