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
ll n,m,ans=1,mod=998244353;cin>>n>>m;
set<char>s[500*2+1];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char c;cin>>c;
        s[i+j].insert(c);
    }
}

for(auto i:s)
    if(i.count('R')&&i.count('B'))ans=0;

if(!ans){
    cout<<0;return 0;
}

for(auto i:s)
    if(i.size()==1&&*i.begin()=='.')
        ans=(ans*2)%mod;

cout<<ans;
}
