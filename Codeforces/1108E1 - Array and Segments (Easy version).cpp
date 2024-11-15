#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();
ll n,m;cin>>n>>m;
ll x[n+1],ans=-1e18;
pair<ll,ll>y[m];
for(int i=1;i<=n;i++)cin>>x[i];
for(auto&[a,b]:y)cin>>a>>b;

vector<ll>out;
for(int i=1;i<=n;i++){
    vector<ll>pre(n+5),v;
    ll mx=-1e18,mn=1e18,id=1;

    for(auto[a,b]:y){
        if(a>i||b<i)
            pre[a]++,pre[b+1]--,v.push_back(id);

        id++;
    }

    for(int i=1;i<=n;i++){
        pre[i]+=pre[i-1];
        mx=max(mx,x[i]-pre[i]),
        mn=min(mn,x[i]-pre[i]);
    }

    if(mx-mn>ans)
        ans=mx-mn,out=v;
}

cout<<ans<<'\n'<<out.size()<<'\n';
for(auto i:out)cout<<i<<' ';
}
