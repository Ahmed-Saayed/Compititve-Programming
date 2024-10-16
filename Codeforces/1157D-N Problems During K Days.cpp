#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll sum(ll n){return n*(n+1)/2;}

int main()
{
Ahmed_Sayed();
ll n,k;cin>>n>>k;
ll x[k],pre=0,prev=-1;

for(int i=0;i<k;i++){
    x[i]=prev+1;

    ll l=1,r=!i?1e9:prev-1,m;
    while(l<=r){
        m=l+r>>1;
        ll num=x[i]+m;

        (sum(num+k-i-1)-sum(num)+pre+num>n?r=m-1:l=m+1);
    }

    x[i]+=r,prev=x[i],pre+=x[i];
}

if(pre==n){
    cout<<"YES\n";
    for(auto i:x)cout<<i<<' ';
}
else cout<<"NO";
}