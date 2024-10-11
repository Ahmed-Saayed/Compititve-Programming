#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=81;
ll n,x[N],dp[N][N][N][N],vis[N][N][N][N],mysize,id,mod=998244353;

ll rec(int i=0,int prev=0,int prev2=0,int sz=0){
    if(i==n||sz==mysize||n-i+sz<mysize)return sz==mysize;

    ll&ret=dp[i][prev][prev2][sz];
    if(vis[i][prev][prev2][sz]==id)return ret;
    vis[i][prev][prev2][sz]=id;

    ret=rec(i+1,prev,prev2,sz)%mod;

    if(sz>=2){
        if(x[i]-x[prev]==x[prev]-x[prev2])
            ret=(ret+rec(i+1,i,prev,sz+1))%mod;
    }
    else
        ret=(ret+rec(i+1,sz==1?i:0,!sz?i:prev2,sz+1))%mod;

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n;
for(int i=0;i<n;i++)cin>>x[i];

cout<<n<<' ';
for(int i=2;i<=n;i++){
    mysize=i,id++;
    cout<<rec()<<' ';
}
}
