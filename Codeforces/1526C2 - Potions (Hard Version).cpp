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
ll n,sm=0;cin>>n;
ll x[n],ans=0;
priority_queue<ll>pq;
for(auto&i:x){
    cin>>i;

    if(sm+i>=0){
        sm+=i,ans++;
        if(i<0)pq.push(-i);
    }

    else if(pq.size()&&pq.top()>-i){
        sm+=pq.top(),sm+=i,pq.pop(),pq.push(-i);
    }
}

cout<<ans;
}
