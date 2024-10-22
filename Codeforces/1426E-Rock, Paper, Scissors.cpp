#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll n, aa, bb, cc, aa1, bb1, cc1;
ll rec(ll a = aa,ll b = bb ,ll c = cc,ll a1 = aa1,ll b1 = bb1,ll c1 = cc1){
    ll ret=0,mn;

    mn=min(a1, b);
    if(mn)ret = mn + rec(a, b - mn, c, a1 - mn, b1, c1);

    mn=min(b1, c);
    if(mn)ret = max(ret, mn + rec(a, b, c - mn, a1, b1 - mn, c1));

    mn=min(c1, a);
    if(mn)ret = max(ret, mn + rec(a - mn, b, c, a1, b1, c1 - mn));


    mn=min(a1, a);
    if(mn)ret = max(ret, mn + rec(a - mn, b, c, a1 - mn, b1, c1));

    mn=min(b1, b);
    if(mn)ret = max(ret, mn + rec(a, b - mn, c, a1, b1 - mn, c1));

    mn=min(c1, c);
    if(mn)ret = max(ret, mn + rec(a, b, c - mn, a1, b1, c1 - mn));

    return ret;
}

int main()
{
Ahmed_Sayed();
cin >> n >> aa >> bb >> cc >> aa1 >> bb1 >> cc1;
ll mx= min(aa ,bb1) + min(bb , cc1) + min(cc , aa1);

cout << n - rec() << ' ' << mx;
}
