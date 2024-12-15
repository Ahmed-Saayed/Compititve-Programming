#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll n,m;
vector<ll>par;
vector<pair<ll,ll>>adj[(ll)1e5+1];
void dijkstra(){
    priority_queue<array<ll,2>,vector<array<ll,2>>,greater<>>pq;
    vector<ll>dis(n+1,1e18);
    pq.push({0,1});

    while(pq.size()){
        auto [cost,node]=pq.top();pq.pop();
        if(cost>dis[node])continue;
        dis[node]=cost;

        for(auto[a,b]:adj[node]){
            if(cost+b<dis[a])dis[a]=cost+b,par[a]=node,pq.push({cost+b,a});
        }
    }
}

int main()
{
Ahmed_Sayed();
cin>>n>>m;
par=vector<ll>(n+1);

while(m--){
    ll a,b,c;cin>>a>>b>>c,adj[a].push_back({b,c}),adj[b].push_back({a,c});
}
dijkstra();

vector<ll>ans;
ll o=n;
while(o)ans.push_back(o),o=par[o];
reverse(all(ans));

if(!par[n])cout<<-1;
else for(auto i:ans)cout<<i<<' ';
}