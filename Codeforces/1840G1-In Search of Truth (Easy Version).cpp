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
ll x;cin>>x;
vector<ll>v={x};
int mp[(ll)1e6+1]{};
mp[x]=1;

int cnt=1;
while(cnt<=999){
    cout<<"+ 1"<<endl;
    cnt++;

    ll o;cin>>o;
    if(mp[o]){cout<<"! "<<cnt-1;return 0;}

    mp[o]=cnt,
    v.push_back(o);
}


while(1){
    cout<<"+ 1000"<<endl;
    cnt+=1e3;

    ll o;cin>>o;

    if(mp[o]){cout<<"! "<<cnt-mp[o];return 0;}
}
}