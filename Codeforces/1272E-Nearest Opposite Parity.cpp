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
int n,x[N];
vector<int>adj[N];
vector<int>bfs(int o){
    vector<int>dis(n,1e9);
    queue<int>q;

    for(int i=0;i<n;i++)
        if(x[i]%2!=o)dis[i]=0,q.push(i);

    while(q.size()){
        int node=q.front();q.pop();

        for(auto i:adj[node]){
            if(x[i]%2==o&&dis[node]+1<dis[i])
                dis[i]=dis[node]+1,q.push(i);
        }
    }

    return dis;
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=0;i<n;i++){
    cin>>x[i];

    if(i+x[i]<n)adj[i+x[i]].push_back(i);
    if(i-x[i]>=0)adj[i-x[i]].push_back(i);
}
vector<int>ans(n),dis;

dis=bfs(0);
for(int i=0;i<n;i++)
    if(x[i]%2==0)ans[i]=dis[i];

dis=bfs(1);
for(int i=0;i<n;i++)
    if(x[i]%2)ans[i]=dis[i];

for(auto i:ans)
    cout<<(i==1e9?-1:i)<<' ';
}