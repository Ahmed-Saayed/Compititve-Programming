#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int dp[(ll)1e6+6];
int rec(int n){
    if(!n)return 0;

    int&ret=dp[n];
    if(~ret)return ret;

    ret=1e9;

    string s=to_string(n);
    for(int j=0;j<s.size();j++)
        ret=min(ret,1+rec(n-s[j]+'0'));

    return ret;
}
int main()
{
Ahmed_Sayed();
int n;cin>>n;
memset(dp,-1,sizeof dp);

cout<<rec(n);
}
