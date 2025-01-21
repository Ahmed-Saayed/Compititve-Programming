#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll x,y,a,b;
bool ok(int m){
    ll l=0,r=m,md;
    while(l<=r){
        md=l+r>>1;

        ll xx=md*a+(m-md)*b;
        ll yy=md*b+(m-md)*a;

        if(xx<=x&&yy<=y)return 1;

        (xx>x?l=md+1:r=md-1);
    }

    return 0;
}

int main()
{
Ahmed_Sayed();
tt
cin>>x>>y>>a>>b;
if(a>b)swap(a,b);

ll l=0,r=1e9;
while(l<=r){
    int m=l+r>>1;

    (ok(m)?l=m+1:r=m-1);
}

cout<<r<<'\n';}
}
