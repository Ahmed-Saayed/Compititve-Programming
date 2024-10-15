#include <bits/stdc++.h>
#define ll int
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
ll n,m,k;cin>>n>>m>>k;
vector<vector<ll>>pre(n+2,vector<ll>(m+2));
char x[n+2][m+2];

for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        cin>>x[i][j],pre[i][j]+=pre[i][j-1]+(x[i][j]=='#');

if(n>m){
    swap(n,m);
    pre=vector<vector<ll>>(n+2,vector<ll>(m+2));

for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        pre[i][j]+=pre[i][j-1]+(x[j][i]=='#');

}

ll ans=0;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        ll sm=0;
        for(int o=i;o<=min(n,i+k);o++){
            ll p=min(m,j+abs(o-(i+k)));
            sm+=pre[o][p]-pre[o][j-1];
        }
        ans=max(ans,sm);

        sm=0;
        for(int o=i;o>=max(1,i-k);o--){
            ll p=min(m,j+abs(o-(i-k)));
            sm+=pre[o][p]-pre[o][j-1];
        }
        ans=max(ans,sm);

        sm=0;
        for(int o=i;o<=min(n,i+k);o++){
            ll p=max(0,j-abs(o-(i+k))-1);
            sm+=pre[o][j]-pre[o][p];
        }
        ans=max(ans,sm);

        sm=0;
        for(int o=i;o>=max(1,i-k);o--){
            ll p=max(0,j-abs(o-(i-k))-1);
            sm+=pre[o][j]-pre[o][p];
        }

        ans=max(ans,sm);
    }

cout<<ans<<'\n';}
}