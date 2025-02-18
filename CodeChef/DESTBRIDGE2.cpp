
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
ll n,c;cin>>n>>c;
deque<ll>v(n);
for(auto&i:v)cin>>i;
ll o=v[0];
v.pop_front();
sort(all(v));
v.push_back(o);

ll l=1,r=n-1,m;
while(l<=r){
    m=(l+r)/2;
    ll sm=0;

    for(int i=0;i<m&&sm<=c;i++)
        for(int j=m;j<n&&sm<=c;j++)sm+=v[i]*v[j];

    (sm<=c?l=m+1:r=m-1);
}

o=0;
for(int i=0;i<n-1;i++)o+=v[i]*v.back();
if(o<=c)r=n-1;
cout<<n-r<<'\n';}
}