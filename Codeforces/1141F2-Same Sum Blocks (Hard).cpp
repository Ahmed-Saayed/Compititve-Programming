#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e6;
vector<pair<ll,ll>>v;
ll dp[N],vis[N],id;
ll rec(int i=0){
    if(i==v.size())return 0;

    ll&ret=dp[i];
    if(vis[i]==id)return ret;
    vis[i]=id;

    ret=rec(i+1);

    pair<ll,ll>p={v[i].second+1,0};
    return ret=max(ret,1+rec((lower_bound(all(v),p))-v.begin()));
}

void bul(int i=0){
    if(i==v.size())return;

    ll best=rec(i);

    if(best==rec(i+1))
        return bul(i+1);

    pair<ll,ll>p={v[i].second+1,0};
    cout<<v[i].first+1<<' '<<v[i].second+1<<'\n';
    bul((lower_bound(all(v),p))-v.begin());
}

int main()
{
Ahmed_Sayed();
int n;cin>>n;
ll x[n];
map<ll,vector<pair<ll,ll>>>mp;
for(int i=0;i<n;i++)cin>>x[i];

for(int i=0;i<n;i++){
    ll sm=0;
    for(int j=i;j<n;j++){
        sm+=x[j];
        mp[sm].push_back({i,j});
    }
}

ll mx=0,sm;
for(auto&[a,b]:mp){
    sort(all(b)),id++,v=b;

    if(rec()>mx)sm=a;
    mx=max(mx,rec());
}

v=mp[sm],id++;
cout<<mx<<'\n';
bul();
}