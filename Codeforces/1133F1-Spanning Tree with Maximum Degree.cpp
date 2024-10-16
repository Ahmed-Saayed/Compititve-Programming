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
int n,m;cin>>n>>m;
vector<int>adj[n+1];

while(m--){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

int mx=0,node;
for(int i=1;i<=n;i++)
    if(mx<(int)adj[i].size())
        mx=(int)adj[i].size(),node=i;

int vis[n+1]{};
queue<int>q;
q.push(node);
vis[node]=1;

vector<pair<int,int>>ans;
while(q.size()){
    node=q.front();q.pop();

    for(auto i:adj[node])
        if(!vis[i])
            vis[i]=1,q.push(i),ans.push_back({node,i});
}

for(auto[a,b]:ans)
    cout<<a<<' '<<b<<'\n';
}