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
vector<int>adj[N],MxPath;
int mx,o;
void dfs(int node,int par,int d){
    MxPath[node]=max(MxPath[node],d);
 
    if(d>mx)
        mx=d,o=node;
 
    for(auto i:adj[node])
        if(i!=par)dfs(i,node,d+1);
}
 
int main()
{
Ahmed_Sayed();
int n;cin>>n;
MxPath=vector<int>(n+1);
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
 
dfs(1,0,0);
mx=0;
dfs(o,0,0);
dfs(o,0,0);
 
for(int i=1;i<=n;i++)
    cout<<MxPath[i]<<' ';
}
