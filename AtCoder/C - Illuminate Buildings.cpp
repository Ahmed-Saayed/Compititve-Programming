#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=3e3+5;
int n,x[N],dp[N][N][3];
int rec(int i=1,int prev=0,int o=0){
    if(i>n||(o==2&&x[i]!=x[prev]))return 0;

    int&ret=dp[i][prev][o];
    if(~ret)return ret;

    if(o<2)
        ret=rec(i+1,prev,o);

    if(!o)
        ret=max(ret,1+rec(i+1,i,1));

    else if(o==1&&x[i]==x[prev])
        ret=max(ret,1+rec(i+(i-prev),i,2));

    else if(o==2)
        ret=max(ret,1+rec(i+(i-prev),i,o));

    return ret;
}
int main()
{
Ahmed_Sayed();
cin>>n;
memset(dp,-1,sizeof dp);
for(int i=1;i<=n;i++)cin>>x[i];

cout<<rec();
}
