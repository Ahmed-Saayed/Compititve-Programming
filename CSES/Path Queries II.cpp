#include <bits/stdc++.h>
#define ll long long
#define ll int
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5,sqr=500;
vector<ll>adj[N],x;

ll blk[sqr],n;
vector<ll>blocks[sqr];
void bul(){
    fill(blk,blk+sqr,0);

    for(int i=0;i<n;i++)
        blocks[i/sqr].push_back(x[i]),
        blk[i/sqr]=max(blk[i/sqr],x[i]);
}

void up(int id,int val){
    blocks[id/sqr][id%sqr]=val,
    x[id]=val;

    ll mn=0;
    for(int i=0;i<sqr;i++)
        mn=max(mn,blocks[id/sqr][i]);

    blk[id/sqr]=mn;
}

int get(int l,int r){
    ll ret=0;

    while(l<=r){
        if(l%sqr==0&&l+sqr-1<=r)
            ret=max(ret,blk[l/sqr]),l+=sqr;

        else
            ret=max(ret,x[l++]);
    }
    return ret;
}

struct HLD{
    vector<ll>heavy,head,par,id,dep,sz;
    int nxt;

    HLD(int n):heavy(n+1),head(n+1),id(n+1),par(n+1),dep(n+1),sz(n+1,1){
        Dfs();
        nxt=0;
        head[1]=1;
        Flatten();
    }

    void Dfs(int node=1){
        for(auto i:adj[node]){
            if(i==par[node])continue;

            par[i]=node;
            dep[i]=dep[node]+1;
            Dfs(i);
            sz[node]+=sz[i];

            if(!heavy[node]||sz[i]>sz[heavy[node]])heavy[node]=i;
        }
    }

    void Flatten(int node=1){
        id[node]=nxt++;

        if(heavy[node])
            head[heavy[node]]=head[node],
            Flatten(heavy[node]);

        for(auto i:adj[node]){
            if(i==par[node]||i==heavy[node])continue;

            head[i]=i;
            Flatten(i);
        }
    }

    int Path(int u,int v){
        int ans=0;

        while(1){
            if(head[u]==head[v]){
                if(dep[u]>dep[v])swap(u,v);

                ans=max(ans,get(id[u],id[v]));
                return ans;
            }

            if(dep[head[u]]>dep[head[v]])swap(u,v);
            ans=max(ans,get(id[head[v]],id[v]));
            v=par[head[v]];
        }
    }

    vector<ll>Get_Array_which_i_Query_On(vector<int>x){
        vector<ll>ret(x.size());
        for(int i=1;i<x.size();i++)ret[id[i]]=x[i];

        return ret;
    }

};


int main()
{
Ahmed_Sayed();
int n2,q;cin>>n2>>q;n=n2;
vector<int>arr(n+1);
for(int i=1;i<=n;i++)cin>>arr[i];
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,

    adj[a].push_back(b),
    adj[b].push_back(a);
}

HLD op(n);
x=op.Get_Array_which_i_Query_On(arr);
bul();

while(q--){
    int o;cin>>o;
    if(o==1){
        int node,val;cin>>node>>val;

        up(op.id[node],val);
    }
    else{
        int u,v;cin>>u>>v;

        cout<<op.Path(u,v)<<' ';
    }
}

}
