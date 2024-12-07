#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N = 500;
ll n, X, k, dp[N][50001][2];
array<ll, 3>x[N];
ll rec(int i = 0, ll sm = 0, bool p = 0){
    if(i == n)return 0;

    ll ok = (i + 1 == n || x[i][2] != x[i + 1][2]), &ret = dp[i][sm][p];
    if(~ret)return ret;

    ret = p * ok * k + rec(i + 1, sm , !ok * p), p = 1;

    if(sm + x[i][0] <= X)
        ret = max(ret, p * ok * k + x[i][1] + rec(i + 1, sm + x[i][0], !ok * p));

    return ret;
}

bool cmp(array<ll,3>x, array<ll,3>y){
    return x[2] < y[2];
}

int main()
{
Ahmed_Sayed();
cin>> n >> X >> k,
memset(dp, -1, sizeof dp);

for(int i = 0 ;i < n; i++)
    cin >> x[i][0] >> x[i][1] >> x[i][2];

sort(x, x + n, cmp);

cout<<rec();
}
