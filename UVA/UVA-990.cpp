#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll t,w,n;
pair<ll,ll>x[50];
ll dp[50][2000];
vector<pair<ll,ll>>ans;
ll rec(ll sm=0,ll i=0){
    if(i==n)return 0;

    ll&ret=dp[i][sm];
    if(~ret)return ret;

    if(sm+3*w*x[i].first<=t)ret=x[i].second+rec(sm+3*w*x[i].first,i+1);
    return ret=max(ret,rec(sm,i+1));
}

void bul(vector<pair<ll,ll>>v,ll sm=0,ll i=0){
    if(i==n){ans=v;return;}

    if(sm+3*w*x[i].first<=t&&x[i].second+rec(sm+3*w*x[i].first,i+1)>=rec(sm,i+1))v.push_back({x[i].first,x[i].second}),bul(v,sm+3*w*x[i].first,i+1);
    else bul(v,sm,i+1);
}

int main()
{
Ahmed_Sayed();
int c=0;
while(cin>>t>>w>>n){
ans.clear();
if(c++)nn;
for(int i=0;i<n;i++)cin>>x[i].first>>x[i].second;
memset(dp,-1,sizeof dp);

vector<pair<ll,ll>>k;
cout<<rec()<<'\n';
bul(k);
cout<<ans.size()<<'\n';
for(auto [a,b]:ans)cout<<a<<' '<<b<<'\n';
}
}
