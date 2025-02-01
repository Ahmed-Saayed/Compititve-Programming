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
tt
int n,ret=-1;cin>>n,n*=2;
int x[n];
map<int,int>mp;
for(auto&i:x)
    cin>>i,mp[i]++;

sort(x,x+n);
vector<int>v;
vector<pair<int,int>>ans;

for(int i=0;i<n-1;i++)
    v.push_back(x[i]+x[n-1]);

for(auto i:v){

    int val=i,p=1;
    auto tmp=mp;
    ans.clear();

    while(mp.size()&&p){
        int a=mp.rbegin()->first,b=val-a;

        if((a==b&&mp[a]>1)||(a!=b&&mp[a]&&mp[b]))
            ans.push_back({a,b}),val=max(a,b),mp[a]--,mp[b]--;
        else
            p=0;

        while(mp.size()&&!mp.rbegin()->second)
            mp.erase(mp.rbegin()->first);
    }

    if(p){
        ret=i;break;
    }
    else
        ans.clear();

    mp=tmp;
}

if(~ret){
    cout<<"YES\n"<<ret<<'\n';
    for(auto [a,b]:ans)
        cout<<a<<' '<<b<<'\n';
}
else cout<<"NO\n";
}
}
