#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=5e3+1;
int n,m,pre[2][N][N],dp[N][N];
int rec(int i=0,int c=0){
    if(i==m)return 0;

    int&ret=dp[i][c];
    if(~ret)return ret;

    ret=pre[0][i+1][c+1]+pre[1][i+1][i-c]+rec(i+1,c+1);
    return ret=max(ret,pre[0][i+1][c]+pre[1][i+1][i-c+1]+rec(i+1,c));
}

int main()
{
Ahmed_Sayed();
cin>>n>>m,
memset(dp,-1,sizeof dp);

for(int i=0,c=0;i<n;i++){
    int o;cin>>o;
    if(!o)c++;
    else if(o>0)pre[0][c][o]++;
    else pre[1][c][-o]++;
}

for(int i=0;i<=m;i++)
    for(int k=1;k<N;k++)
        pre[0][i][k]+=pre[0][i][k-1],
        pre[1][i][k]+=pre[1][i][k-1];

cout<<rec();
}
