#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int n,x,v[100],dp[(ll)1e6+1];
int rec(int sm=x){
    if(sm<=0)return !sm?0:1e9;
 
    int&ret=dp[sm];
    if(~ret)return ret;
 
    ret=1e9;
    for(int i=0;i<n;i++)
        ret=min(ret,1+rec(sm-v[i]));
    return ret;
}
 
int main()
{
Ahmed_Sayed();
cin>>n>>x;
memset(dp,-1,sizeof dp);
for(int i=0;i<n;i++)cin>>v[i];
 
int ans=rec();
cout<<(ans>=1e9?-1:ans);
}