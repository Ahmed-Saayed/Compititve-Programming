
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
ll n,m;cin>>n>>m;
ll l=0,r=1e9,md;
while(l<=r){
    md=(l+r)/2;
    if((n*10+100*md)/(10+md)<m)l=md+1;else r=md-1;
}
cout<<l<<'\n';}
}