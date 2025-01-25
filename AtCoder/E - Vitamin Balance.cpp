#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int n;
array<int,3>x[(ll)1e5];					//  https://atcoder.jp/contests/abc390/tasks/abc390_e
ll dp[5000][5001][4],id=1;
ll rec(int i,int sm,int o){
    if(sm<0)return -1e18;
    if(i==n)return 0;

    ll&ret=dp[i][sm][o];
    if(~ret)return ret;

    ret=rec(i+1,sm,o);

    if(x[i][0]==o)
        ret=max(ret,x[i][1]+rec(i+1,sm-x[i][2],o));

    return ret;
}

int main()
{
Ahmed_Sayed();
ll k;cin>>n>>k;
for(int i=0;i<n;i++)
    cin>>x[i][0]>>x[i][1]>>x[i][2];

memset(dp,-1,sizeof dp);

ll l=0,r=1e10,m1;
while(l<=r){
    m1=l+r>>1;

    ll cost=k;
    bool p=1;

    for(int i=1;i<=3&&p;i++){
        ll l2=0,r2=cost,m2;
        while(l2<=r2){
            m2=l2+r2>>1;

            (rec(0,m2,i)<m1?l2=m2+1:r2=m2-1);
        }

        if(l2>cost)p=0;
        cost-=l2;
    }

    (p?l=m1+1:r=m1-1);
}

cout<<r;
}
