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
tt
int n,k;cin>>n>>k;
set<int>adj[n+1],ans,s;

for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].insert(b),
    adj[b].insert(a);
}

for(int i=1;i<=n;i++)
    if(adj[i].size()==1)s.insert(i);

while(k--){
    set<int>q;

    for(auto i:s){
        ans.insert(i);
        if(!adj[i].size())continue;

        int node=*adj[i].begin();
        if(adj[node].size()<=2)q.insert(node);

        adj[node].erase(i);
    }

    if(!q.size())break;
    s=q;
}
if(n==1)ans.insert(1);
cout<<n-ans.size()<<'\n';}
}