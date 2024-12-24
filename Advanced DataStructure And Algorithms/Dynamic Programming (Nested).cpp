#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){						//598E - Chocolate Bar
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll n1,m1,k1,dp[31][31][51];
ll rec(int n=n1,int m=m1,int k=k1){
    if(k<0||k>n*m)return 1e18;
    if(!k||k==n*m)return 0;

    ll&ret=dp[n][m][k];
    if(~ret)return ret;

    ret=1e18;

    for(int a=1;a<m;a++)
        ret=min(ret,n*n+min(rec(n,a,k-(m-a)*n),rec(n,m-a,k)));

    for(int a=1;a<n;a++)
        ret=min(ret,m*m+min(rec(a,m,k-(n-a)*m),rec(n-a,m,k)));

    return ret;
}

int main()
{
Ahmed_Sayed();
memset(dp,-1,sizeof dp);
tt
cin>>n1>>m1>>k1;
cout<<rec()<<'\n';}
}