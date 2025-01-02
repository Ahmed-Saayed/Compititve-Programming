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
ll N=2e5+1,n,k,nums=0,sm=0,ans=1;cin>>n>>k;
ll fre[N]{},mn=1e9,mx=0;
while(n--){
    ll o;cin>>o,fre[o]++;
    mn=min(mn,o),mx=max(mx,o);
}
if(mn==mx){
    cout<<0;return 0;
}

for(int i=N-1;i>=mn;i--){
    if(sm-i*nums>k){
        ans++,i++;
        sm=nums*i;

        continue;
    }

    sm+=fre[i]*i,
    nums+=fre[i];
}

cout<<ans;
}
