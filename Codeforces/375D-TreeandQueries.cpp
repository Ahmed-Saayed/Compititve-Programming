#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int sqr=500,N=1e5+5;
vector<int>adj[N],v;

struct query{
    int l,r,idblk,idq,k;

    query(){}

    query(int _l,int _r,int _idq,int kk){
        l=_l,r=_r,idq=_idq,idblk=l/sqr,k=kk;
    }

    bool operator<(const query&q)const{
        if(idblk!=q.idblk)return idblk<q.idblk;

        return r<q.r;
    }
};

query qu[N];
int n,q,x[N],vis[(ll)1e6+6],fre[(ll)1e6+6],FF[(ll)1e6+6];
ll ans[N],blk[N],ret;

void add(int node){
    vis[node]++;

    if(vis[node]==2){
        fre[x[node]]++;

        FF[fre[x[node]]]++,
        blk[fre[x[node]]/sqr]++;

        FF[fre[x[node]]-1]--,
        blk[(fre[x[node]]-1)/sqr]--;
    }
}

void del(int node){
    vis[node]--;

    if(vis[node]==1){
        fre[x[node]]--;

        FF[fre[x[node]]]++,
        blk[fre[x[node]]/sqr]++;

        FF[fre[x[node]]+1]--,
        blk[(fre[x[node]]+1)/sqr]--;
    }
}

ll get(int l){
    ll ret=0;

    while(l<=n){
        if(l%sqr)
            ret+=FF[l++];
        else
            ret+=blk[l/sqr],l+=sqr;
    }
    return ret;
}

int timer,in[N],out[N];
void MOsTree(){
    sort(qu,qu+q);

    int l=1,r=0;

    for(int i=0;i<q;i++){
        int a=v[qu[i].l],b=v[qu[i].r],k=qu[i].k;

        while(l<qu[i].l)del(v[l++]);
        while(l>qu[i].l)add(v[--l]);

        while(r<qu[i].r)add(v[++r]);
        while(r>qu[i].r)del(v[r--]);

         ans[qu[i].idq]=get(k);
    }

    for(int i=0;i<q;i++)
        cout<<ans[i]<<'\n';
}

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
cin>>n>>q;
for(int i=1;i<=n;i++)cin>>x[i];
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
dfs();

for(int i=0;i<q;i++){
    int node,k;cin>>node>>k;

    qu[i]=query(in[node],out[node],i,k);
}
MOsTree();
}
