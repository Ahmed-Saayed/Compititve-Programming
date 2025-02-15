#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;
							// D - Swap to Gather contests/abc393 
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll sum(ll n){
    return n*(n+1)/2;
}
int main()
{
Ahmed_Sayed();
ll n;
string s;
cin>>n>>s,s='*'+s;

ll pre=0,presm=0,suf=0,ones=0,sufsm=0,ans=1e18;
for(ll i=1;i<=n;i++)
    if(s[i]=='1')pre++,ones++,presm+=i;

for(ll i=n;i;i--){

    if(s[i]=='1')
        pre--,presm-=i,suf++,sufsm+=i;

    ll sm=0;

    if(suf)
        sm+=sufsm-(sum(i+suf-1)-sum(i-1));

    if(pre)
        sm+=(sum(i-1)-sum(i-1-pre))-presm;

    ans=min(ans,sm);
}

cout<<ans;
}
