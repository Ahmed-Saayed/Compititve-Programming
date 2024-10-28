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
ll n,m,ans=0;cin>>n>>m;
ll x[n],id;
for(int i=0;i<n;i++){
    cin>>x[i];
    if(x[i]==m)id=i;
}
map<ll,ll>mp;
mp[0]++;
int sm=0;
for(int i=id+1;i<n;i++){
    sm+=(x[i]>m?1:-1);
    mp[sm]++;
}

sm=0;
for(int i=id;~i;i--){
    sm+=(x[i]<=m?1:-1);

    ans+=mp[sm]+mp[sm-1];
}

cout<<ans;
}