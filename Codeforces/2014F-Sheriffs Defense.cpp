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
ll n,c,x[N],dp[N][2];
vector<int>adj[N];
ll rec(int node=1,int par=0,int o=0){

    ll&ret=dp[node][o],op1=0;
    if(~ret)return ret;

    for(auto i:adj[node])
        if(i!=par)op1+=rec(i,node,0);

    ll op2=x[node]-(o!=0)*c*2;
    for(auto i:adj[node])
        if(i!=par)op2+=rec(i,node,1);

    return ret=max(op1,op2);
}

int main()
{
Ahmed_Sayed();
tt
cin>>n>>c;
for(int i=1;i<=n;i++)
    cin>>x[i],dp[i][0]=dp[i][1]=-1,adj[i].clear();

for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b,
    adj[a].push_back(b),
    adj[b].push_back(a);
}

cout<<rec()<<'\n';}
}
