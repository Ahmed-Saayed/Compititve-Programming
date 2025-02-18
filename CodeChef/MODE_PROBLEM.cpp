#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();
ll n,q;cin>>n>>q;
ll x[n],ans=0;
map<ll,ll>mp;
for(auto&i:x)cin>>i,ans+=++mp[i];

while(q--){
    ll id,val;cin>>id>>val,id--;
    ans-=mp[x[id]]--;
    ans+=++mp[val];
    x[id]=val;
    cout<<ans<<'\n';
}
}
