#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll calc(int m,vector<ll>&x){
    return x.end()-lower_bound(all(x),m)+1;
}

int main()
{
Ahmed_Sayed();
tt
ll n,m,kev,good;cin>>n>>m;
vector<ll>x(n),y(m);
for(auto&i:x)cin>>i;
for(auto&i:y)cin>>i;

kev=x[0];
sort(all(x)),sort(all(y));

good=upper_bound(all(y),kev)-y.begin();

for(int k=1;k<=m;k++){
    ll sz=m/k*k,small=min(sz,good),rem;

    ll ans=small/k;
    rem=sz-small;


    for(int i=m-rem;i<m;i+=k)
        ans+=calc(y[i],x);

    cout<<ans<<' ';
}
nn;}
}
