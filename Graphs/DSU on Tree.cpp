#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){                                     // CodeForces - 375D
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=5e5+5;
vector<int>adj[N];
int big[N],sz[N],fre[N][26],dep[N],ans[N];
string s;

void pre(int node,int par){
    sz[node]=1;
    for(auto i:adj[node]){
        if(i==par)continue;

        pre(i,node);

        sz[node]+=sz[i];

        if(!big[node]||sz[i]>sz[big[node]])
            big[node]=i;
    }
}

void up(int node,int add){
    fre[dep[node]][s[node]-'a']+=add;
}

void collect(int node,int par,int add){
    up(node,add);

    for(auto i:adj[node])
        if(i!=par)collect(i,node,add);
}

vector<pair<int,int>>v[N];
void dfs(int node,int par,int ok){
    for(auto i:adj[node])
        if(i!=par&&big[node]!=i)
            dfs(i,node,0);

    if(big[node])
        dfs(big[node],node,1);

    up(node,1);

    for(auto i:adj[node])
        if(i!=par&&i!=big[node])
            collect(i,node,1);

    for(auto[a,b]:v[node]){
        int c=0;

        for(int i=0;i<26&&c<2;i++)
            c+=fre[a][i]%2;

        ans[b]=c<2;
    }

    if(!ok)
        collect(node,par,-1);
}

void dfs2(int node,int par,int dis){
    dep[node]=dis;

    for(auto i:adj[node])
        if(i!=par)dfs2(i,node,dis+1);
}

int main()
{
Ahmed_Sayed();
int n,m;cin>>n>>m;
for(int i=2;i<=n;i++){
    int par;cin>>par;
    adj[par].push_back(i);
    adj[i].push_back(par);
}
cin>>s,s='*'+s;

for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;

    v[a].push_back({b,i});
}

dfs2(1,0,1);
pre(1,0);
dfs(1,0,0);

for(int i=0;i<m;i++)cout<<(ans[i]?"Yes":"No")<<'\n';
}
