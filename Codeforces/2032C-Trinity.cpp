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
int n;cin>>n;
int x[n],ans=1e9;
for(auto&i:x)cin>>i;
sort(x,x+n);

for(int i=n-1;~i;i--){
    int l=0,r=i-1,m;
    while(l<=r){
        m=l+r>>1;

        (x[m]+x[m+1]<=x[i]?l=m+1:r=m-1);
    }
    ans=min(ans,int(l+(n-(upper_bound(x,x+n,x[i])-x))));
}

cout<<ans<<'\n';}
}
