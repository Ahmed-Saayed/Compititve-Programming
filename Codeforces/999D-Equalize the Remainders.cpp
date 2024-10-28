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
ll n,m;cin>>n>>m;
ll x[n],ans=0;
set<int>s;
map<ll,ll>mp;
for(auto&i:x)cin>>i,mp[i%m]++;
for(int i=0;i<m;i++)
    if(mp[i]<n/m)s.insert(i);

for(auto&i:x){
    int mod=i%m;

    if(mp[mod]>n/m){
        mp[mod]--;
        auto it=s.upper_bound(mod);

        if(it==s.end())
            it=s.begin(),ans+=m-mod,i+=m-mod;

        ans+=*it-i%m,i+=*it-i%m;
        mp[i%m]++;
    }

    if(mp[i%m]==n/m)s.erase(i%m);
}

cout<<ans<<'\n';
for(auto i:x)cout<<i<<' ';
}