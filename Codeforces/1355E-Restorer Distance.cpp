#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void Ahmed_Sayed(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

ll n,g,r,m;
vector<ll>v;
ll can1(ll md) {
    ll a=0,b=0;
    for(auto i:v)
        (i<=md?a+=md-i:b+=i-md);
    ll ret=0,mn=min(a,b);
    ret+=mn*m,
    a-=mn,
    b-=mn;
    return ret+a*g+b*r;
}

ll can2(ll md) {
    ll a=0,b=0;
    for(auto i:v)
        (i<=md?a+=md-i:b+=i-md);

    return a*g+b*r;
}

int main()
{
    file();
    Ahmed_Sayed();
    cin>>n>>g>>r>>m;
    v=vector<ll>(n);
    for(auto&i:v)cin>>i;

    ll lef=0,rig=1e12,md;
    while (lef<=rig) {
        md=(lef+rig)/2;
        if(g+r>m) {
            can1(md)>can1(md+1)?lef=md+1:rig=md-1;
        }
        else {
            can2(md)>can2(md+1)?lef=md+1:rig=md-1;
        }
    }
    cout<<(g+r>m?can1(lef):can2(lef));
}