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
map<int,int>vis;
vector<int>v(n),ans;

queue<int>q;
for(int i=0;i<n;i++){
    cin>>v[i],
    q.push(v[i]),vis[v[i]]=1;
}
sort(all(v));

while(q.size()){
    int node=q.front();q.pop();

    if(ans.size()<m&&!vis[node+1])
        vis[node+1]=1,ans.push_back(node+1),q.push(node+1);

    if(ans.size()<m&&!vis[node-1])
        vis[node-1]=1,ans.push_back(node-1),q.push(node-1);
}

ll sm=0;
for(auto i:ans){
    auto it=upper_bound(all(v),i);

    ll o1=it==v.end()?1e18:*it-i,o2=it==v.begin()?1e18:i-*(--it);

    sm+=min(o1,o2);
}

cout<<sm<<'\n';
for(auto i:ans)cout<<i<<' ';
}
