#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

struct DSU{
    vector<ll>par,sz;
    ll sm,components;

    DSU(){}
    DSU(int n){
        sm=0,components=n;
        par=sz=vector<ll>(n+1);
        for(int i=0;i<=n;i++)par[i]=i,sz[i]=1;
    }

    ll findlead(ll n){
        if(par[n]==n)return n;
        return par[n]=findlead(par[n]);
    }

    bool merge(ll x,ll y,ll c){
        x=findlead(x),y=findlead(y);
        if(x==y)return 0;

        sm+=c,components--;
        if(sz[x]>=sz[y])sz[x]+=sz[y],par[y]=x;
        else sz[y]+=sz[x],par[x]=y;
        return 1;
}
};

int main()
{
Ahmed_Sayed();
int n,m,q;cin>>n>>m;
vector<DSU>pre(m+1),suf(m+1);
vector<pair<int,int>>edg(m+1);

for(int i=1;i<=m;i++){
    cin>>edg[i].first>>edg[i].second;

    if(i>1)
        pre[i]=pre[i-1];
    else
        pre[i]=DSU(n);

    pre[i].merge(edg[i].first,edg[i].second,0);
}

for(int i=m;i;i--){
    if(i!=m)
        suf[i]=suf[i+1];
    else
        suf[i]=DSU(n);

    suf[i].merge(edg[i].first,edg[i].second,0);
}

cin>>q;
while(q--){
    int l,r;cin>>l>>r;

    DSU ans(n);

    for(int i=1;i<=n;i++){
        if(l>1)
            ans.merge(i,pre[l-1].findlead(i),0);
        if(r<m)
            ans.merge(i,suf[r+1].findlead(i),0);
    }

    cout<<ans.components<<'\n';
}
}
