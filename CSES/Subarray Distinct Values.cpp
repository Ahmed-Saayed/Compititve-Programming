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
ll n,k,ans=0;cin>>n>>k;
int x[n],o=0;
for(auto&i:x)cin>>i;
map<int,int>mp;
set<int>s;

for(int i=0;i<n;i++){
    s.insert(x[i]);
    mp[x[i]]++;

    while(s.size()>k){
        mp[x[o]]--;
        if(!mp[x[o]])s.erase(x[o]);
        o++;
    }

    ans+=i-o+1;
}

cout<<ans;
}
