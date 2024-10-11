#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n,k,dp[1<<12][100];
ll rec(ll mask=0,ll cnt=0){
    if(cnt>k)return 0;
    if(mask==(1<<n)-1)return cnt==k;

    ll &ret=dp[mask][cnt];
    if(~ret)return ret;

    ret=0;
    for(int i=0;i<n;i++){
        if((mask>>i)&1)continue;
        int c=0;
        for(int j=i+1;j<n;j++)if((mask>>j)&1)c++;
        ret+=rec(mask|(1<<i),cnt+c);
    }
    return ret;
}

int main()
{
Ahmed_Sayed();
tt
cin>>n>>k;
for(int i=0;i<1<<n;i++)
    for(int j=0;j<=k;j++)dp[i][j]=-1;
cout<<rec()<<'\n';
}
}
