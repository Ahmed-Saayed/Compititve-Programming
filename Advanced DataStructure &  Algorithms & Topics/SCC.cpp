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
int in[N],vis[N],dn[N],low[N],id;
stack<int>st;
vector<vector<int>>comp;
void SCC(ll node){
    dn[node] = low[node] = id++;
    st.push(node);
    in[node] = 1,vis[node]=1;

    for(auto&i:adj[node]){
        if(i == node)continue;
        if(!dn[i]){
            SCC(i);
            low[node] = min(low[node],low[i]);
        }else if(in[i]){
            low[node] = min(low[node],dn[i]);
        }
    }
    if(dn[node] == low[node]){
        ll x = -1;
        comp.push_back({});

        while(x!=node){
            x = st.top();
            st.pop();
            in[x] = 0;
            comp.back().push_back(x);
        }
    }
}

int main()
{
Ahmed_Sayed();
int n,m;cin>>n>>m;
while(m--){
    int u,v;cin>>u>>v,
    adj[u].push_back(v);
}

for(int i=1;i<=n;i++)
    if(!vis[i])SCC(i);

for(auto i:comp){
    for(auto j:i)cout<<j<<' ';
    nn;
}
}
