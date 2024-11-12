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
ll n,c,x[N],y[N],ans[N];
void dijkstra(){
    priority_queue<array<ll,3>,vector<array<ll,3>>,greater<>>pq;
    vector<vector<ll>>dis(n+1,vector<ll>(2,1e18));

    pq.push({0,1,0});
    while(pq.size()){
        auto[cost,node,stat]=pq.top();pq.pop();

        if(cost>dis[node][stat])continue;
        dis[node][stat]=cost,ans[node]=min(ans[node],cost);

        if(node==n)return;

        if(cost+x[node]<dis[node+1][0])
                dis[node+1][0]=cost+x[node],pq.push({cost+x[node],node+1,0});

        if(stat){
            if(cost+y[node]<dis[node+1][1])
                dis[node+1][1]=cost+y[node],pq.push({cost+y[node],node+1,1});
        }
        else{
            if(cost+y[node]+c<dis[node+1][1])
                dis[node+1][1]=cost+y[node]+c,pq.push({cost+y[node]+c,node+1,1});
        }
    }
}

int main()
{
Ahmed_Sayed();
cin>>n>>c;
for(int i=1;i<n;i++)cin>>x[i];
for(int i=1;i<n;i++)cin>>y[i],ans[i]=ans[i+1]=1e18;
dijkstra();

for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
}
