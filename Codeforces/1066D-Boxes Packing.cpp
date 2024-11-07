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
ll n,m,k;cin>>n>>m>>k,m--;
ll x[n];
for(auto&i:x)cin>>i;

int l=-1,r=n-1,md;
while(l<=r){
    md=l+r>>1;
    int i=md+1,k2=k,m2=m;

    while(i<n){
        if(x[i]>k2){
            if(!m2)break;
            m2--,k2=k;
        }

        k2-=x[i],i++;
    }

    (i==n?r=md-1:l=md+1);
}

cout<<n-l-1;
}