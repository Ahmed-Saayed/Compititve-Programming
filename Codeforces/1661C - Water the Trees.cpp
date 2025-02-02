#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=3e5;
int n,x[N],ok;

ll calc(ll a){
    ll l=0,r=1e18,m,tot=0;

    for(int i=0;i<n;i++)
        tot+=(x[n-1]-(x[i]+(x[i]%2!=x[n-1]%2)))/2;

    while(l<=r){
        m=l+r>>1;

        if((m+1)/2<a){l=m+1;continue;}

        ll one=(m+1)/2,two=m/2;

        one-=a,
        one/=2;

        (one+two<tot?l=m+1:r=m-1);
    }

    ll one=(l+1)/2-a;

    ok|=(one%2);

    return l;
}

int calc2(){
    int a=0;
    for(int i=0;i<n;i++)
        a+=(x[i]%2!=x[n-1]%2);

    return a;
}

int main()
{
Ahmed_Sayed();
tt
cin>>n;
for(int i=0;i<n;i++)cin>>x[i];
sort(x,x+n);

ll a=calc2(),ans=calc(a);

ok=0;
x[n-1]++;
a=calc2();

cout<<min(calc(a)+!ok,ans)<<'\n';}
}
