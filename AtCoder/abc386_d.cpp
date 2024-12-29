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
vector<pair<int,int>>v1,v2;
while(m--){
    int a,b;char c;cin>>a>>b>>c;

    if(c=='B')
        v1.push_back({a,b});
    else
        v2.push_back({a,b});
}
sort(all(v2));
int mn=1e9,pre[(int)v2.size()];

for(int i=0;i<v2.size();i++){
    mn=min(mn,v2[i].second);

    pre[i]=mn;
}

bool ans=1;
for(auto [a,b]:v1){
    int id=lower_bound(all(v2),make_pair(a+1,0))-v2.begin()-1;

    if(~id&&pre[id]<=b)ans=0;
}

cout<<(ans?"Yes":"No")<<'\n';
}
