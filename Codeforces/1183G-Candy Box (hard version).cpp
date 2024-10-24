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
tt
ll n;cin>>n;
vector<vector<ll>>fre(n+1,vector<ll>(2));
for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    fre[a][b]++;
}

vector<ll>mp[n+1];
for(int i=1;i<=n;i++)
    mp[fre[i][0]+fre[i][1]].push_back(fre[i][1]);

ll ans1=0,ans2=0;
priority_queue<ll>pq;
for(ll i=n;i;i--){
    for(auto j:mp[i])pq.push(j);

    if(pq.size()){
        ans1+=i,ans2+=min(i,pq.top());
        pq.pop();
    }
}

cout<<ans1<<' '<<ans2<<'\n';}
}