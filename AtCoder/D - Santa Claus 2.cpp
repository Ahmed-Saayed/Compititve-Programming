#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

set<pair<ll,ll>>ans;
void ok(set<ll>&s,ll l,ll r,ll o,bool stat){
    auto it=s.lower_bound(l);

    set<ll>q;
    for(;it!=s.end()&&*it<=r;it++){
        ans.insert(stat?make_pair(*it,o):make_pair(o,*it)),
        q.insert(*it);
    }

    for(auto i:q)s.erase(i);
}

int main()
{
Ahmed_Sayed();
ll n,m,x,y;cin>>n>>m>>x>>y;
map<ll,set<ll>>mpx,mpy;


while(n--){
    int a,b;cin>>a>>b,

    mpx[a].insert(b),
    mpy[b].insert(a);
}


while(m--){
    int a;char c;
    cin>>c>>a;

    if(c=='R'){
        ll up=x+a;

        ok(mpy[y],x,up,y,1);
        x+=a;
    }

    if(c=='L'){
        ll up=x-a;

        ok(mpy[y],up,x,y,1);
        x-=a;
    }

    if(c=='U'){
        ll up=y+a;

        ok(mpx[x],y,up,x,0);
        y+=a;
    }

    if(c=='D'){
        ll up=y-a;

        ok(mpx[x],up,y,x,0);
        y-=a;
    }
}

cout<<x<<' '<<y<<' '<<ans.size();
}
