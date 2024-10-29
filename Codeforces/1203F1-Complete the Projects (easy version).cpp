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
int n,r;cin>>n>>r;
vector<pair<int,int>>pos;
vector<array<int,3>>neg;

while(n--){
    int a,b;cin>>a>>b;

    if(b<0)neg.push_back({a+b,a,b});
    else pos.push_back({a,b});
}
sort(all(pos)),sort(all(neg)),reverse(all(neg));

bool ans=1;
for(auto [a,b]:pos){
    if(a>r){ans=0;break;}

    r+=b;
}
if(!ans){cout<<"NO";return 0;}

for(auto [c,a,b]:neg){
    if(a>r){ans=0;break;}

    r+=b;
}
if(r<0)ans=0;
cout<<(ans?"YES":"NO");
}