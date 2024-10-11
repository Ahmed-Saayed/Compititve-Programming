#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
map<pair<ll,ll>,set<char>>mp;
ll n,a,b,c,d,dp[50][50];
ll rec(ll i=a,ll j=b){
    if(i==c&&j==d)return 1;
    if(i>n||j>n)return 0;

    ll&ret=dp[i][j];
    if(~ret)return ret;

    ret=0;
    if(mp[{i,j}].find('N')==mp[{i,j}].end())ret+=rec(i,j+1);
    if(mp[{i,j}].find('E')==mp[{i,j}].end())ret+=rec(i+1,j);
    return ret;
}
int main()
{
Ahmed_Sayed();
tt
cin>>n>>a>>b>>c>>d;
memset(dp,-1,sizeof dp);
mp.clear();
ll w;cin>>w;
while(w--){
    char f;
    ll x,y;cin>>x>>y>>f;
if(f=='N')mp[{x,y}].insert('N');
if(f=='E')mp[{x,y}].insert({'E'});
if(f=='W')mp[{x-1,y}].insert('E');
if(f=='S')mp[{x,y-1}].insert('N');
}
cout<<rec();nn;}
}
