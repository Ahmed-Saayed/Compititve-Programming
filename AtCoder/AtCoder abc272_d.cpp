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
int n,m,dx[4]{1,1,-1,-1},dy[4]{1,-1,1,-1};cin>>n>>m;

vector<vector<ll>>dis(n,vector<ll>(n,1e18));
queue<pair<int,int>>q;
q.push({0,0});
dis[0][0]=0;

while(q.size()){
    auto[i,j]=q.front();q.pop();

        for(ll k=0;k*k<=m;k++){
            ll k2=m-k*k;

            if(sqrt(k2)!=(int)sqrt(k2))continue;

                k2=sqrt(k2);

                for(int o=0;o<4;o++){
                    ll a=i+dx[o]*k,b=j+dy[o]*k2;

                    if(min(a,b)>=0&&max(a,b)<n&&dis[i][j]+1<dis[a][b])
                        dis[a][b]=dis[i][j]+1,q.push({a,b});
                }
            }
    }

for(auto i:dis){
    for(auto j:i)cout<<(j==1e18?-1:j)<<' ';
    nn;
}
}
