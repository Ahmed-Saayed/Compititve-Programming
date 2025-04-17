#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();


ll n,m;cin>>n>>m;
ll x[n],a=-1,b,c,d;
for(auto&i:x)cin>>i;

map<int,set<pair<int,int>>>mp;

for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)mp[x[i]+x[j]].insert({i,j});


for(int i=0;i<n-1&&a==-1;i++)
    for(int j=i+1;j<n&&a==-1;j++){
        ll sm=m-(x[i]+x[j]);
        if(sm<0||!mp.count(sm))continue;

        bool ok=0;
        for(auto[i2,j2]:mp[sm])
            if(i!=i2&&i!=j2&&j!=i2&&j!=j2){
                a=i+1,b=j+1,c=i2+1,d=j2+1;
                break;
            }
    }

if(a==-1)
    cout<<"IMPOSSIBLE";
else
    cout<<a<<' '<<b<<' '<<c<<' '<<d;
}
