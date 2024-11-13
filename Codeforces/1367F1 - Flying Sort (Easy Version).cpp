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
int n;cin>>n;
vector<int>x(n),v;
for(auto&i:x)cin>>i;

v=x;
sort(all(v));
for(auto&i:x)
    i=lower_bound(all(v),i)-v.begin()+1;

int ans=1e9;
for(int i=0;i<=n;i++){
    vector<int>tmp;
    int c=0,id=0;
    for(auto j:x)
        if(j>i)tmp.push_back(j);

    vector<int>o=tmp;
    sort(all(o));

    for(auto i:tmp)
        if(o[id]==i)id++;

    ans=min(ans,i+(int)tmp.size()-id);
}

cout<<ans<<'\n';}
}
