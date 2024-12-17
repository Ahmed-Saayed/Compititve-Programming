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
tt
ll n,ans,k;cin>>n>>k;
ans=n*(n+1)/2;

ll pre[n+1]{},suf[n+1];
for(int i=1;i<=n;i++)
    cin>>pre[i],pre[i]+=pre[i-1];

for(int i=1;i<=n;i++){
    int l=i,r=n,m;
    while(l<=r){
        m=l+r>>1;

        (pre[m]-pre[i-1]<=k?l=m+1:r=m-1);
    }

    suf[i]=l;
}

ll dp[n+2]{};
for(int i=n;i;i--)
    if(suf[i]<=n){
        dp[i]=1+dp[suf[i]+1];
        ans-=dp[i];
    }

cout<<ans<<'\n';}
}
