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
int n,m;cin>>n>>m;
vector<int>a(n);
for(auto&i:a)cin>>i;
vector<pair<int,int>>b(m);
for(int i=0;i<m;i++){
    cin>>b[i].first,b[i].second=i;
}

sort(all(b));

vector<int>ans(m,-1);
for(int i=0;i<n;i++){
    while(b.size()&&b.back().first>=a[i])
        ans[b.back().second]=i+1,b.pop_back();
}

for(auto i:ans)cout<<i<<'\n';
}
