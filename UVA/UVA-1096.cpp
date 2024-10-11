#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

double dis(ll a,ll b,ll c,ll d){
    return sqrt(abs(a-c)*abs(a-c)+abs(b-d)*abs(b-d));
}

ll n,a,b,vis[100][100][100][3],id=0,cnt=1;
double dp[100][100][100][3];

pair<ll,ll>x[100];
double rec(ll i=2,ll prev=1,ll prev2=0,ll o=min(a,b)==1){
    if(i==n)return(o==1?dis(x[n-1].first,x[n-1].second,x[prev2].first,x[prev2].second):1e9);

    double&ret=dp[i][prev][prev2][o];
    if(vis[i][prev][prev2][o]==id)return ret;
    vis[i][prev][prev2][o]=id;

    ret=dis(x[i].first,x[i].second,x[prev].first,x[prev].second)+rec(i+1,i,prev2,o+(i==a||i==b));
    if(i!=n-1)ret=min(ret,dis(x[i].first,x[i].second,x[prev2].first,x[prev2].second)+rec(i+1,prev,i,o));
    return ret;
}

vector<ll>bak;
void bul(ll i=2,ll prev=1,ll prev2=0,ll o=min(a,b)==1){
    if(i==n)return;

    double best=rec(i,prev,prev2,o);
    if(best==dis(x[i].first,x[i].second,x[prev].first,x[prev].second)+rec(i+1,i,prev2,o+(i==a||i==b))){
        cout<<i<<' ';
        bul(i+1,i,prev2,o+(i==a||i==b));
    }
    if(i!=n-1&&best==dis(x[i].first,x[i].second,x[prev2].first,x[prev2].second)+rec(i+1,prev,i,o)){
        bak.push_back(i);
        bul(i+1,prev,i,o);
    }
}


int main()
{
Ahmed_Sayed();
while(cin>>n>>a>>b&&n){
    id++,bak.clear();
for(int i=0;i<n;i++)cin>>x[i].first>>x[i].second;
cout<<"Case "<<cnt++<<": "<<fixed<<setprecision(2)<<rec()+dis(x[0].first,x[0].second,x[1].first,x[1].second)<<'\n';

cout<<"0 1 ";
bul();
reverse(all(bak));
for(auto i:bak)cout<<i<<' ';
cout<<0;
nn;}
}
//