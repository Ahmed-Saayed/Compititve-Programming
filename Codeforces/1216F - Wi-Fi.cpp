#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,k,dp[(ll)2e5+5];
vector<int>v;
ll rec(int i=n-1){
    if(i<0)return 0;

    ll&ret=dp[i];
    if(~ret)return ret;

    ret=i+1+rec(i-1);

    auto it=lower_bound(all(v),i-k);
    if(it!=v.end()&&*it-i<=k)
        ret=min(ret,*it+1+rec(*it-k-1));

    return ret;
}

int main()
{
Ahmed_Sayed();
string s;cin>>n>>k>>s;
memset(dp,-1,sizeof dp);

for(int i=0;i<n;i++)
    if(s[i]=='1')v.push_back(i);

cout<<rec();
}
