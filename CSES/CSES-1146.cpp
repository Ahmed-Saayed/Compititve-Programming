#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();
ll n,ans=0;cin>>n;
n++;

for(ll i=0;(1ll<<i)<=n-1;i++){
    if(n/(1ll<<i)%2)
        ans+=n%(1ll<<i);

    ans+=n/(1ll<<(i+1))*(1ll<<i);
}

cout<<ans;
}
