#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N = 2e5 + 5;
vector<int>adj[N];
int val[N],a,b;
set<int>s;
int dfs1(int node = a,int par = 0){
    int ret = s.count(node);

    if(node == b)ret = 2;

    for(auto i:adj[node])
        if(i != par)ret = max(ret ,dfs1(i,node));

    return val[node] = ret;
}

int dfs2(int node = a,int par = 0){
    int ret = 0;
    for(auto i: adj[node])
        if(i != par)ret += dfs2(i, node) + (val[i] == 1? 2 : 1) * (val[i] != 0);

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
int n,k;cin>>n>>k>>a>>b;

s.clear(),
fill(adj,adj + n + 1,vector<int>()),
fill(val,val + n + 1,0);

while(k--){
    int o;cin>>o;s.insert(o);
}

for(int i=0;i<n-1;i++){
    int a,b;cin>> a >> b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
dfs1();
cout<<dfs2()<<'\n';}
}
