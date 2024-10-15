#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=70;
int n,m,k,v[N*N],dp[N*N][N][N];
int rec(int i=0,int sm=0,int cnt=0){
    if(i==n*m)return !sm?0:-1e9;

    int&ret=dp[i][sm][cnt];
    if(~ret)return ret;

    ret=rec(i+1,sm,(i+1)%m==0?0:cnt);

    if(cnt<m/2)
        ret=max(ret,v[i]+rec(i+1,(sm+v[i])%k,(i+1)%m==0?0:cnt+1));

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n>>m>>k,
memset(dp,-1,sizeof dp);
for(int i=0;i<n*m;i++)cin>>v[i];

cout<<rec();
}
