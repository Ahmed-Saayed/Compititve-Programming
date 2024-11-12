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
int n,k;cin>>n>>k;
pair<int,int>x[n];
int par[202]{};
for(auto&[a,b]:x)
    cin>>a>>b,par[a]++,par[b+1]--;

for(int i=1;i<=200;i++)
    par[i]+=par[i-1];

vector<int>ans,vis(n);
for(int i=1;i<=200;i++)
    while(par[i]>k){

        int mx=0,id=-1;
        for(int j=0;j<n;j++)
            if(x[j].first<=i&&x[j].second>=i&&x[j].second>mx&&!vis[j])
                mx=x[j].second,id=j;

        ans.push_back(id+1),vis[id]=1;
        for(int j=x[id].first;j<=x[id].second;j++)par[j]--;
    }

cout<<ans.size()<<'\n';
for(auto i:ans)cout<<i<<' ';
}
