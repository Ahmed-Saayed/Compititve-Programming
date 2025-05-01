#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
string s,t;
ll dp[20][12][2][2][2];
ll rec(ll i=0,ll prev=-1,bool f1=0,bool f2=0,bool put=0){
    if(i==s.size())return 1;
 
    ll&ret=dp[i][prev+1][f1][f2][put];
    if(~ret)return ret;
 
    ret=0;
    ll l=(!f1?s[i]-'0':0),r=(!f2?t[i]-'0':9);
    for(int j=l;j<=r;j++){
        if(!j&&!put)
            ret+=rec(i+1,j,!(!f1&&j==l),!(!f2&&j==r),put);
 
        else if(j!=prev)
            ret+=rec(i+1,j,!(!f1&&j==l),!(!f2&&j==r),put|(j!=0));
    }
    return ret;
}
 
int main()
{
Ahmed_Sayed();
cin>>s>>t;
while(s.size()<t.size())s='0'+s;
memset(dp,-1,sizeof dp);
cout<<rec();
}