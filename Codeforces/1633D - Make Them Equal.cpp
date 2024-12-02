#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e3;
int n,k,x[N],c[N],dp[N][(ll)5e4],dis[N+1];
int rec(int i,int cost){
    if(cost<0)return -1e9;
    if(i==n)return 0;

    int&ret=dp[i][cost];
    if(~ret)return ret;

    ret=rec(i+1,cost);
    return ret=max(ret,c[i]+rec(i+1,cost-dis[x[i]]));
}


void dijkstra(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,1});

    while(pq.size()){
        auto[cost,node]=pq.top();pq.pop();

        if(cost>dis[node]||node>1e3)continue;
        dis[node]=cost;

        for(int i=1;i<=node;i++)
            if(cost+1<dis[node+node/i])
                dis[node+node/i]=cost+1,pq.push({cost+1,node+node/i});
    }
}

int main()
{
Ahmed_Sayed();
fill(dis,dis+N+1,1e9);
dijkstra();

tt
int sm=0;
cin>>n>>k;
for(int i=0;i<n;i++)
    cin>>x[i],sm+=dis[x[i]];

k=min(k,sm);
for(int i=0;i<n;i++)
    cin>>c[i],fill(dp[i],dp[i]+k+1,-1);

cout<<rec(0,k)<<'\n';}
}
