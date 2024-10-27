#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int n,m;
vector<ll>a,b;
vector<vector<ll>>dp;
ll rec(int i=0,int j=0){
    if(i==n)return 0;

    ll&ret=dp[i][j];
    if(~ret)return ret;

    ret=1e9;
    if(j+1<m)ret=rec(i,j+1);

    int l=i,r=n-1,md;
    while(l<=r){
        md=l+r>>1;

        (a[md]-(i?a[i-1]:0)>b[j]?r=md-1:l=md+1);
    }
    if(r>=i)
        ret=min(ret,m-j-1+rec(r+1,j));

    return ret;
}


int main()
{
Ahmed_Sayed();
tt
cin>>n>>m;
a=vector<ll>(n),b=vector<ll>(m);
dp=vector<vector<ll>>(n,vector<ll>(m,-1));

for(int i=0;i<n;i++)cin>>a[i],a[i]+=(i?a[i-1]:0);
for(int i=0;i<m;i++)cin>>b[i];

ll ans=rec();
cout<<(ans>=1e9?-1:ans)<<'\n';}
}
