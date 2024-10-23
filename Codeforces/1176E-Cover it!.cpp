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
tt
int n,m,eve=0,odd=0;cin>>n>>m;
vector<int>ans,dis(n+1),adj[n+1];

while(m--){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

queue<int>q;
q.push(1);
dis[1]=1;

while(q.size()){
    int node=q.front();q.pop();

    (dis[node]%2?odd+=1:eve+=1);

    for(auto i:adj[node])
        if(!dis[i])dis[i]=dis[node]+1,q.push(i);
}

int o=eve>odd;

for(int i=1;i<=n;i++)
    if(dis[i]%2==o)ans.push_back(i);

cout<<ans.size()<<'\n';
for(auto i:ans)cout<<i<<' ';
nn;}
}