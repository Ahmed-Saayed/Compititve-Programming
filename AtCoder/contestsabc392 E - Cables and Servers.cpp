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

    DSU(ll n){
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
int n,m;cin>>n>>m;
DSU op(n);

vector<pair<int,int>>edg(m);
vector<int>v;
for(int i=0;i<m;i++){
    cin>>edg[i].first>>edg[i].second;

    if(!op.merge(edg[i].first,edg[i].second,0))
        v.push_back(i);
}

set<int>st;
for(int i=1;i<=n;i++)
    st.insert(op.findlead(i));

while(v.size()>st.size()-1)v.pop_back();

cout<<v.size()<<'\n';
for(int i=0;i<v.size();i++){
    cout<<v[i]+1<<' '<<edg[v[i]].second<<' ';

    for(auto j:st)
        if(op.findlead(j)!=op.findlead(edg[v[i]].second)){
            cout<<op.findlead(j)<<'\n';

            op.merge(op.findlead(edg[v[i]].second),op.findlead(j),0),
            st.erase(j);
            break;
        }
}
}
