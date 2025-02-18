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
ll n;cin>>n;
set<ll>s;
for(int i=1;i<=n;i++)s.insert(i);

for(int i=1;i<=n;i++)cout<<i<<' ';
nn;

ll o=n/2;
for(int i=1;i<=n;i++){
    if(i+o>n)cout<<*s.begin()<<' ',s.erase(s.begin());
    else cout<<i+o<<' ',s.erase(i+o);
}
nn;}
}