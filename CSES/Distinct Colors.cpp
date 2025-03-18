#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--)  {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5;
vector<int>adj[N];
set<int>st[N];
int x[N],ans[N];
void dfs(int node=1,int par=0){
    st[node].insert(x[node]);
 
    for(auto i:adj[node]){
        if(i!=par){
            dfs(i,node);
 
            if(st[node].size()<st[i].size())
                swap(st[node],st[i]);
 
            for(auto j:st[i])st[node].insert(j);
        }
    }
 
    ans[node]=st[node].size();
}
 
 
int main()
{
Ahmed_Sayed();
int n;cin>>n;
for(int i=1;i<=n;i++)cin>>x[i];
 
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
 
dfs();
 
for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
}
