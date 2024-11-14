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
vector<int>adj[N];
int n;

vector<ll>bfs(int node){
    queue<pair<int,int>>q;
    vector<ll>dis(n+1,1e18);
    q.push({0,node});
    dis[node]=0;

    while(q.size()){
        auto[cost,node]=q.front();q.pop();

        for(auto i:adj[node])
            if(cost+1<dis[i])
                dis[i]=cost+1,q.push({cost+1,i});
    }

    return dis;
}

int main()
{
Ahmed_Sayed();
tt
int m,a,b,c;cin>>n>>m>>a>>b>>c;

fill(adj,adj+n+1,vector<int>());

vector<ll>pre(m+1);
for(int i=1;i<=m;i++)cin>>pre[i];
for(int i=0;i<m;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

sort(all(pre));
for(int i=1;i<=m;i++)pre[i]+=pre[i-1];

vector<ll>dis1=bfs(a),dis2=bfs(b),dis3=bfs(c);

ll ans=1e18;
for(int i=1;i<=n;i++){
    int way=dis1[i]+dis2[i]+dis3[i];

    if(way<=m)
        ans=min(ans,pre[way]+pre[dis2[i]]);
}

cout<<ans<<'\n';}
}
