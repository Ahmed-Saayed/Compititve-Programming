#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

bool cmp(array<int,4>x,array<int,4>y){
    return x[1]<y[1];
}

int main()
{
Ahmed_Sayed();
int n,m,o=1;cin>>n>>m;
vector<array<int,4>>v(m);
for(auto&[a,b,c,d]:v)
    cin>>a>>b>>c,d=o++;

sort(all(v),cmp);

int vis[n+1]{},ans=1;
for(auto&[a,b,c,d]:v){
    o=a;

    while(o<b&&c){
        if(!vis[o])c--,vis[o]=d;
        o++;
    }
    vis[b]=m+1;
    if(c){ans=0;break;}
}
if(!ans)cout<<-1;
else for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
}
