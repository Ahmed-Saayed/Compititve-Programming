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
ll N=1e6;

vector<ll>prime(N+1),small(N+1),pri;
prime[1]=1;
for(ll i=2;i<=N;i++)
    if(!prime[i]){
        small[i]=i,pri.push_back(i);
    for(ll j=i*i;j<=N;j+=i){
        if(!small[j])small[j]=i;
        prime[j]=1;
    }
}

tt
ll n,ans=0;cin>>n;
for(auto i:pri){
    if(i>small[n])break;
    ans+=n*i;
}
cout<<ans<<'\n';}
}
