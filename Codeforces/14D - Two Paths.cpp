#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=300;
vector<int>adj[N];
map<pair<int,int>,int>mp;
int mx,o;
void dfs(int node,int par,int dis){
    if(dis>mx)
        mx=dis,o=node;

    for(auto i:adj[node])
        if(i!=par&&!mp.count({i,node}))dfs(i,node,dis+1);
}

int calc(int node){
    mx=0,o=node;
    dfs(node,0,0);
    mx=0;

    dfs(o,0,0);

    return mx;
}

int main()
{
Ahmed_Sayed();
int n;cin>>n;
vector<pair<int,int>>v(n-1);
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);

    v[i]={a,b};
}

int ans=0;
for(auto [i,j]:v){
    mp.clear();
    mp[{i,j}]=mp[{j,i}]=1;
    ans=max(ans,calc(i)*calc(j));
}

cout<<ans;
}
