#include <bits/stdc++.h>
#define ll long long
#define int long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5;
vector<pair<int,int>>adj[N];
int n,m;
ll dijkstra(){
    vector<vector<ll>>dis(n+1,vector<ll>(2,1e18));
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<>>pq;
    pq.push({0,1,0});
    while(pq.size()){
        auto[cost,node,ok]=pq.top();pq.pop();

        if(node==n)return cost;

        if(cost>dis[node][ok])continue;
        dis[node][ok]=cost;

        for(auto [a,b]:adj[node]){
            if(cost+b<dis[a][ok])
                dis[a][ok]=cost+b,pq.push({cost+b,a,ok});

            if(!ok&&cost+b/2<dis[a][1])
                dis[a][1]=cost+b/2,pq.push({cost+b/2,a,1});
        }
    }
}

int32_t main()
{
Ahmed_Sayed();
cin>>n>>m;
while(m--){
    int a,b,c;cin>>a>>b>>c;
    adj[a].push_back({b,c});
    //adj[b].push_back({a,c});
}

cout<<dijkstra();
}
