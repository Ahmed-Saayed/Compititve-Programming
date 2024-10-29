#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

bool cmp(pair<int,int>p,pair<int,int>p2){
    if(p.first+p.second!=p2.first+p2.second)
        return p.first+p.second>p2.first+p2.second;
}

int n,r,dp[100][(ll)1e5];
vector<pair<int,int>>pos,neg;
int rec(int i=0,int rem=r){
    if(i==neg.size())return 0;

    int&ret=dp[i][rem];
    if(~ret)return ret;

    ret=rec(i+1,rem);

    if(rem>=neg[i].first&&rem+neg[i].second>=0)
        ret=max(ret,1+rec(i+1,rem+neg[i].second));

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n>>r;
memset(dp,-1,sizeof dp);

for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;

    if(b<0)neg.push_back({a,b});
    else pos.push_back({a,b});
}
sort(all(pos)),sort(all(neg),cmp);

int ans=0;
for(auto [a,b]:pos){
    if(a>r)break;

    r+=b,ans++;
}

cout<<ans+rec();
}