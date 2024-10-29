#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

const int N=2e5+5;
int sqr;
struct query{
    int l,r,idblk,idq;

    query(){}

    query(int _l,int _r,int _idq){
        l=_l,r=_r,idq=_idq,idblk=l/sqr;
    }

    bool operator<(const query&q)const{
        if(idblk!=q.idblk)return idblk<q.idblk;

        return r<q.r;
    }
};

query qu[N];
ll n,x[N],fre[(ll)1e6+6],FF[(ll)1e6+6],vis[N],col[(ll)1e6+6],ret;
ll ans[N];

vector<int>v{0},adj[N];

void add(int id){
    vis[id]++;

 if(vis[id]==2){
    int f=fre[x[id]];
    if(f==ret)ret++;

    col[fre[x[id]]]-=x[id];
    fre[x[id]]++;
    col[fre[x[id]]]+=x[id];

    FF[f]--,
    FF[f+1]++;
 }
}

void del(int id){
    vis[id]--;

if(vis[id]==1){
    int f=fre[x[id]];
    if(f==ret&&FF[f]==1)ret--;

    col[fre[x[id]]]-=x[id];
    fre[x[id]]--;
    col[fre[x[id]]]+=x[id];

    FF[f]--,
    FF[f-1]++;
 }
}

void MOsTree(){
    sort(qu,qu+n);

    int l=1,r=0;

    for(int i=0;i<n;i++){
        while(l<qu[i].l)del(v[l++]);
        while(l>qu[i].l)add(v[--l]);

        while(r<qu[i].r)add(v[++r]);
        while(r>qu[i].r)del(v[r--]);

        ans[qu[i].idq]=col[ret];
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<' ';
}

int timer=1,in[N],out[N];
void dfs(int node=1,int par=-1){
    in[node]=timer++;
    v.push_back(node);

    for(auto i:adj[node])
        if(i!=par)dfs(i,node);

    out[node]=timer++,
    v.push_back(node);
}

int main()
{
Ahmed_Sayed();
cin>>n,sqr=sqrt(n)+5;
for(int i=1;i<=n;i++)cin>>x[i];
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
dfs();

for(int i=0;i<n;i++){
    qu[i]=query(in[i+1],out[i+1],i);
}
MOsTree();
}
