#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,h,f[30],d[30],t[30],ans[30],dp[30][1000][50];

ll rec(ll o=h,ll val=f[0],ll i=0,ll cnt=0){
    if(o-5<0)return 0;

    ll &ret=dp[i][o][cnt];
    if(~ret)return ret;

    ret=0;
    if(i+1!=n)ret=rec(o-t[i]*5,f[i+1],i+1,0);
    return ret=max(ret,val+rec(o-5,max(0LL,val-d[i]),i,cnt+1));
}

void bul(ll o=h,ll val=f[0],ll i=0,ll cnt=0){
    if(o-5<0)return;

    ll best=val+rec(o-5,max(0LL,val-d[i]),i,cnt+1);
    ll best2=i+1!=n?rec(o-t[i]*5,f[i+1],i+1,0):0;

    if(best>=best2)ans[i]+=5,bul(o-5,max(0LL,val-d[i]),i,cnt+1);
    else bul(o-t[i]*5,f[i+1],i+1,0);
}

int main()
{
Ahmed_Sayed();
int te=0;
while(cin>>n&&n){
if(te++)nn;
cin>>h,h*=60;
for(int i=0;i<n;i++)cin>>f[i];
for(int i=0;i<n;i++)cin>>d[i];
for(int i=0;i<n-1;i++)cin>>t[i];
memset(dp,-1,sizeof dp),memset(ans,0,sizeof ans);

bul();
for(int i=0;i<n;i++){
    cout<<ans[i];
    if(i+1!=n)cout<<", ";
}
nn;
cout<<"Number of fish expected: "<<rec();nn;
}
}
