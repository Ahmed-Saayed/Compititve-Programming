#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,k,v[201],pre[201],dp[201][201];
vector<pair<pair<ll,ll>,ll>>ans;
ll rec(ll cnt=0,ll i=1){
    if(cnt>k)return 1e9;
    if(i>n)return (cnt==k?0:1e9);

    ll &ret=dp[i][cnt];
    if(~ret)return ret;

    ret=1e9;
    for(int j=i;j<=n;j++){
        ll mn=1e9;
        for(int o=i;o<=j;o++)mn=min(mn,(o-i)*v[o]-(pre[o-1]-pre[i-1])+((pre[j]-pre[o])-v[o]*(j-o)));
    ret=min(ret,mn+rec(cnt+1,j+1));
    }
    return ret;
}

void bul(ll cnt=0,ll i=1){
    if(i>n)return;

    for(int j=i;j<=n;j++){
        ll mn=1e9,id=0;
        for(int o=i;o<=j;o++){
                if((o-i)*v[o]-(pre[o-1]-pre[i-1])+((pre[j]-pre[o])-v[o]*(j-o))<=mn)id=o,
                mn=(o-i)*v[o]-(pre[o-1]-pre[i-1])+((pre[j]-pre[o])-v[o]*(j-o));
        if(rec(cnt,i)==mn+rec(cnt+1,j+1)){ans.push_back({{i,j},id}),bul(cnt+1,j+1);return;}
    }
}
}
int main()
{
Ahmed_Sayed();
int t=1;
while(cin>>n>>k&&n){

for(int i=1;i<=n;i++)cin>>v[i],pre[i]=v[i]+pre[i-1];

for(int i=1;i<=n;i++)
for(int j=0;j<=30;j++)dp[i][j]=-1;

ans.clear();

bul();
cout<<"Chain "<<t++<<'\n';
for(int i=0;i<ans.size();i++){
    cout<<"Depot "<<i+1;
    if(ans[i].first.first==ans[i].first.second)cout<<" at restaurant "<<ans[i].second<<" serves restaurant "<<ans[i].first.first;
    else cout<<" at restaurant "<<ans[i].second<<" serves restaurants "<<ans[i].first.first<<" to "<<ans[i].first.second;
    nn;
}
cout<<"Total distance sum = "<<rec()<<'\n';
nn;}
}
