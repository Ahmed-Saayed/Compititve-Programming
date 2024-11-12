#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_multiset <ll> os;

const int N=2e5+5;
int par[N]{};
vector<pair<int,int>>in[N],out[N];

int main()
{
Ahmed_Sayed();
int n,k;cin>>n>>k;
pair<int,int>v[n];

for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;

    int a=v[i].first,b=v[i].second;

    par[a]++,par[b+1]--,
    in[a].push_back({b,i+1}),
    out[b+1].push_back({b,i+1});
}

for(int i=1;i<N;i++)
    par[i]+=par[i-1];

vector<int>ans;
multiset<pair<int,int>>s;
for(int i=1;i<=2e5;i++){

    for(auto [a,b]:out[i]){
        if(s.find({a,b})==s.end())continue;
        s.erase({a,b});
    }
    
    for(auto [a,b]:in[i])
        s.insert({a,b});

    par[i]-=os.size()-os.order_of_key(i);

    while(par[i]>k){
        par[i]--,
        ans.push_back(s.rbegin()->second),
        os.insert(s.rbegin()->first),
        s.erase(*s.rbegin());
    }
}

cout<<ans.size()<<'\n';
for(auto i:ans)cout<<i<<' ';
}
