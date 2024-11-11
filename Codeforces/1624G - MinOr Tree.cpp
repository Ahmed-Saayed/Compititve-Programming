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
    ll sm,edges;

    DSU(ll n){
        sm=0,edges=n;
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

        sm+=c,edges--;
        if(sz[x]>=sz[y])sz[x]+=sz[y],par[y]=x;
        else sz[y]+=sz[x],par[x]=y;
        return 1;
}
};

int main()
{
Ahmed_Sayed();
tt
int n,m;cin>>n>>m;
vector<array<int,3>>v(m);
for(auto&[a,b,c]:v)cin>>b>>c>>a;

int num=(1ll<<31)-1;
for(int i=30;~i;i--){
    num-=1ll<<i;

    DSU op(n);
    for(int j=0;j<v.size()&&op.edges>1;j++)
        if((num&v[j][0])==v[j][0])op.merge(v[j][1],v[j][2],0);

    if(op.edges!=1)num+=1ll<<i;
}

cout<<num<<'\n';}
}
