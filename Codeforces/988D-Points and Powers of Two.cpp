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
int n;cin>>n;
map<int,int>mp;
while(n--){
    int o;cin>>o,mp[o]++;
}
vector<int>ans;
for(auto[a,b]:mp){

    for(int i=0;i<32;i++){
        vector<int>o={a};
        for(int j=0;j<2;j++)
            if(mp.count(o.back()+(1ll<<i)))
                o.push_back(o.back()+(1ll<<i));

        if(ans.size()<o.size())ans=o;
    }
}

cout<<ans.size()<<'\n';
for(auto i:ans)cout<<i<<' ';
}
