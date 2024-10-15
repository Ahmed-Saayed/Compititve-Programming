#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll n,m,k,x[200001],fre[2001],pre[2001],dp[2001];
ll rec(int i=1){
    if(i>n)return 0;

    ll&ret=dp[i];
    if(~ret)return ret;

    ret=x[i]+rec(i+1);

    for(int j=i;j<=n;j++){
        int p=fre[j-i+1];
        ret=min(ret,pre[j]-pre[i+p-1]+rec(j+1));
    }

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n>>m>>k;

for(int i=1;i<=n;i++)cin>>x[i];
sort(x+1,x+n+1);

n=min(n,k);
for(int i=1;i<=n;i++)pre[i]=x[i]+pre[i-1],dp[i]=-1;

while(m--){
    ll a,b;cin>>a>>b;
    fre[a]=max(fre[a],b);
}
cout<<rec();
}