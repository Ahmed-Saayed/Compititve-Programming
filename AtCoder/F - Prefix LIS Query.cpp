#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){						F - Prefix LIS Query contests/abc393
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();
int n,q;cin>>n>>q;
vector<int>v,x(n);
for(auto&i:x)cin>>i;


vector<vector<pair<int,int>>>mp(n);

for(int i=0;i<q;i++){
    int a,b;cin>>a>>b;
    mp[a-1].push_back({b,i});
}

int ans[q];
for(int i=0;i<n;i++){
    if(!v.size()||x[i]>v.back())
        v.push_back(x[i]);
    else
        v[lower_bound(all(v),x[i])-v.begin()]=x[i];

    for(auto [a,b]:mp[i])
        ans[b]=upper_bound(all(v),a)-v.begin();
}

for(auto i:ans)cout<<i<<'\n';
}
