#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

vector<ll>dv(ll n){
    vector<ll>ret;

    for(ll i = 1;i*i <= n; i++)
        if(n % i == 0){
            ret.push_back(i);
            if(i != n / i)ret.push_back(n / i);
        }

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
int n;cin >> n;
int x[n],ans = -1;
for(auto&i:x)cin >> i;

for(int i = 0;i < n; i++){
    int sm = 0;
    vector<int>v;

    for(auto j:x){
        if(j == x[i])sm++;
        else if(j > x[i])v.push_back(j - x[i]);
    }
    if(sm >= n / 2){ans = 1e9;continue;}

    map<ll,ll>mp;
    for(auto i: v)
        for(auto j:dv(i))mp[j]++;

    for(auto[a, b]: mp)
        if(b + sm >= n / 2)ans = max((ll)ans, a);
}

if(ans == 1e9)ans = -1;

cout << ans << '\n';}
}