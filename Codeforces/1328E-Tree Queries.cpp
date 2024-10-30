#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int  N=2e5+5;
int dep[N],parent[N],in[N],out[N],timer;
vector<int>adj[N];
void dfs(int node=1,int par=0){
    dep[node] = dep[par] + 1,
    parent[node] = par,
    in[node] = timer++;

    for(auto i :adj[node])
        if(i!=par)dfs(i,node);

    out[node] = timer++;
}

int main()
{
Ahmed_Sayed();
int n,q;cin>>n>>q;
for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}
dfs();

while(q--){
    int sz,o=-1;cin>>sz;
    vector<int>v(sz);
    for(auto&i:v){
        cin>>i;

        if(~o){
            if(dep[i] > dep[o])o = i;
        }
        else o = i;

        if(i!=1)i=parent[i];
    }

    bool ans=1;
    for(auto i:v)
        ans&=(in[i]<=in[o]&&out[o]<=out[i]);

    cout<<(ans?"YES":"NO")<<'\n';
}
}
