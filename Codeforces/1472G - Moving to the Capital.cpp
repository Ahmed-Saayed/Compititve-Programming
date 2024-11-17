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
vector<int>adj[N],adj2[N],dis;
void bfs(){
    queue<int>q;
    q.push(1),dis[1]=0;

    while(q.size()){
        int node=q.front();q.pop();

        for(auto i:adj[node])
            if(dis[node]+1<dis[i])
                dis[i]=dis[node]+1,q.push(i);
    }
}

int main()
{
Ahmed_Sayed();
tt
int n,m;cin>>n>>m;

fill(adj,adj+n+1,vector<int>()),
fill(adj2,adj2+n+1,vector<int>()),
dis=vector<int>(n+1,1e9);

while(m--){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj2[b].push_back(a);
}
bfs();

vector<int>up(n+1);
for(int i=1;i<=n;i++){
    up[i]=dis[i];

    for(auto j:adj[i])
        up[i]=min(up[i],dis[j]);
}

queue<int>q;
for(int i=1;i<=n;i++)q.push(i);

while(q.size()){
    int node=q.front();q.pop();

    for(auto j:adj2[node])
        if(dis[node]>dis[j]&&up[node]<up[j])
            up[j]=up[node],q.push(j);
}

for(int i=1;i<=n;i++)
    cout<<up[i]<<' ';
    
nn;}
}
