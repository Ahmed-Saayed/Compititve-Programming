#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int n,m,dp[201][201][201];
string s,t;
int rec(int i=0,int k=m,int p=0){
    if(i==n)return 0;

    int&ret=dp[i][k][p];
    if(~ret)return ret;

    ret=(s[i]==t.back())*p+rec(i+1,k,p+(s[i]==t[0]));

    if(k){
        ret=max({ret,
                p+rec(i+1,k-1,p+(t[0]==t.back())),
                (t[0]==t.back())*p+rec(i+1,k-1,p+1)});
    }
    return ret;
}
int main()
{
Ahmed_Sayed();
cin>>n>>m>>s>>t;
memset(dp,-1,sizeof dp);

cout<<rec();
}