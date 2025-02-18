#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

bool prime(ll n){
    for(ll i=2;i*i<=n;i++)if(n%i==0)return 0;
    if(n==1)return 0;
    return 1;
}

int main()
{
Ahmed_Sayed();
vector<ll>v;
for(ll i=1;i<=1e5;i++)
    if(prime(i))v.push_back(i*i);

tt
ll n;cin>>n;
if(!n){cout<<"NO\n";continue;}
for(int i=0;i<v.size()&&n;i++){
    for(int j=i+1;j<v.size()&&n>v[i]+v[j];j++)
        if(n-(v[i]+v[j])!=v[i]&&n-(v[i]+v[j])!=v[j]&&v[i]!=v[j]&&sqrt(n-(v[i]+v[j]))==(ll)sqrt(n-(v[i]+v[j]))&&prime((ll)sqrt(n-(v[i]+v[j])))){
           n=0;break;
        }
}
cout<<(!n?"YES":"NO")<<'\n';}
}