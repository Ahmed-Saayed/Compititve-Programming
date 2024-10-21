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
ll h,n;cin>>h>>n;
ll x[n],sm=0,ans=1e18,pre=0;

for(int i=0;i<n;i++)
    cin>>x[i],sm+=x[i];

for(int i=0;i<n;i++){
    pre+=x[i];

    ll o=h+pre;

    if(o<=0){ans=min(ans,(ll)i+1);break;}

    if(o+sm<o)
        ans=min(ans,n*(o/abs(sm)+(o%abs(sm)!=0))+i+1);
}

if(ans==1e18)ans=-1;
cout<<ans;
}