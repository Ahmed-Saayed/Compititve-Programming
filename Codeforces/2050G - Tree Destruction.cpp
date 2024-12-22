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
int ans;
int dfs(int node=1,int par=0){
    vector<int>v;

    for(auto i:adj[node])
        if(i!=par)v.push_back(dfs(i,node));

    sort(all(v),greater<>());
    ans=max(ans,(int)adj[node].size());

    if(v.size()>=1)
        ans=max(ans,(int)adj[node].size()-1+v[0]);

    if(v.size()>=2)
        ans=max(ans,(int)adj[node].size()-2+v[0]+v[1]);

    int ret=(int)adj[node].size()-1;
    
    if(v.size()>=1)
        ret=max(ret,(int)adj[node].size()-2+v[0]);

    return ret;
}
int main()
{
Ahmed_Sayed();
tt
int n;cin>>n;
ans=0,
fill(adj,adj+n+1,vector<int>());

for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    adj[a].push_back(b),
    adj[b].push_back(a);
}

dfs();
cout<<ans<<'\n';}
}
