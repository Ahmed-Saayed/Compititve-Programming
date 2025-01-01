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
ll n,m,ans=0,N;cin>>n>>m>>N;
vector<vector<ll>>v(n+1,vector<ll>(m+1));
while(N--){
    int a,b;cin>>a>>b,
    v[a][b]++;
}

for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)v[i][j]+=v[i-1][j];

for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)v[i][j]+=v[i][j-1];

for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){

        int l=0,r=min(n-i,m-j);
        while(l<=r){
            int md=l+r>>1,c=i+md,d=j+md;

            (!(v[c][d]-v[i-1][d]-v[c][j-1]+v[i-1][j-1])?l=md+1:r=md-1);
        }

        ans+=++r;
    }
}

cout<<ans;
}
