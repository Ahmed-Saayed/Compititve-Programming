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
int n,up[N],dp[N][2];
int rec(int i=0,bool take=0){
    if(i==n)return 0;

    int&ret=dp[i][take];
    if(~ret)return ret;

    ret=0;
    if(!take)ret=rec(i+1,0);

    return ret=max(ret,1+rec(up[i],1));
}

void bul(int i=0,bool take=0){
    if(i==n)return;

    int best=rec(i,take);

    if(!take&&best==rec(i+1,0))
        return bul(i+1,0);

    if(best==1+rec(up[i],1))
        cout<<i+1<<' ',bul(up[i],1);
}

int main()
{
Ahmed_Sayed();
cin>>n;
memset(dp,-1,sizeof dp);

int x[n];
for(auto&i:x)cin>>i;

map<int,int>mp;
for(int i=n-1;~i;i--){
    up[i]=mp.find(x[i]+1)==mp.end()?n:mp[x[i]+1];
    mp[x[i]]=i;
}
cout<<rec()<<'\n';
bul();
}