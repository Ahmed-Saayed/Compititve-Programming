#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=3e5+5;
vector<int>adj[N],dp;
int rec(int node=1,int par=0){
    if((node==1&&adj[node].size()==1)||(node!=1&&adj[node].size()<=2))
        return (node!=1?adj[node].size():2);

    int&ret=dp[node];
    if(~ret)return ret;

    ret=1e9;
    for(auto i:adj[node])
        if(i!=par)ret=min(ret,2+rec(i,node));

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
int n;cin>>n;

fill(adj,adj+n+1,vector<int>());
dp=vector<int>(n+1,-1);

for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

cout<<n-rec()<<'\n';}
}
