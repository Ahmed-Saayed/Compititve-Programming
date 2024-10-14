#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=103;
ll n,k,clr[N],dp[N][N][N],dp2[N][N][N],mod=1e9+7;
ll rec(int i=0,int sz=0,int colo=0){
    if(i==n)return (sz%k==0?sz:-1e18);

    ll&ret=dp[i][sz][colo];
    if(~ret)return ret;

    ret=rec(i+1,sz,colo);

    if(sz%k==0)
        ret=max(ret,rec(i+1,sz+1,clr[i]));

    else if(clr[i]==colo)
        ret=max(ret,rec(i+1,sz+1,clr[i]));

    return ret;
}

ll rec2(int i=0,int sz=0,int colo=0){
    if(i==n)return (sz==rec());

    ll&ret=dp2[i][sz][colo];
    if(~ret)return ret;

    ret=rec2(i+1,sz,colo)%mod;

    if(sz%k==0)
        ret=(ret+rec2(i+1,sz+1,clr[i]))%mod;

    else if(clr[i]==colo)
        ret=(ret+rec2(i+1,sz+1,clr[i]))%mod;

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
cin>>n>>k;
for(int i=0;i<=n;i++){
    if(i<n)cin>>clr[i];

    for(int j=0;j<=n;j++)
        for(int l=0;l<=n;l++){
            dp[i][j][l]=dp2[i][j][l]=-1;
        }
}

cout<<rec2()<<'\n';}
}