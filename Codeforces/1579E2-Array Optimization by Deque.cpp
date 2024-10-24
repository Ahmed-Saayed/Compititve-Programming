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

int main()
{
Ahmed_Sayed();
tt
ll n,ans=0;cin>>n;
map<int,int>mp;
ordered_multiset <ll> os;

while(n--){
    int o;cin>>o;
    int small=os.order_of_key (o),large=os.size()-(small+mp[o]);

    ans+=min(small,large),
    os.insert(o),mp[o]++;
}

cout<<ans<<'\n';}
}
