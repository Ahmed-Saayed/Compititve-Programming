#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
ll dp[1001][1001];
vector<ll>v,h;

ll rec(ll prev=0,ll i=1){
    if(i==v.size())return 0;

    ll&ret=dp[i][prev];
    if(~ret)return ret;

    if(v[i]>v[prev])ret=1+rec(i,i+1);
    return ret=max(ret,rec(prev,i+1));
}

void bul(vector<ll>ans,ll prev=0,ll i=1){
    if(i==v.size()){
        h=ans;return;
    }

    if(v[i]>v[prev]&&rec(i,i+1)>=rec(prev,i+1))ans.push_back(v[i]),bul(ans,i,i+1);
    else bul(ans,prev,i+1);
}

int main()
{
Ahmed_Sayed();
int t;cin>>t;
for(int i=1;i<=t;i++){
string s;
v.clear(),v.push_back(0),h.clear();
memset(dp,-1,sizeof dp);

if(i==1)getline(cin,s),getline(cin,s);
while(getline(cin,s)){
    if(s.empty())break;
    if(s[0]>='0'&&s[0]<='9')v.push_back(stoll(s));
}

bul(h);
cout<<"Max hits: "<<h.size()<<'\n';
for(auto j:h)cout<<j<<'\n';
if(i<t)nn;
}
}
