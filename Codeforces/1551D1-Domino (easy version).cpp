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
int n,m,k;cin>>n>>m>>k;
cout<<((n%2==0&&m%2==0&&k%2==0)||(n%2&&m%2==0&&k>=m/2&&(k-m/2)%2==0)||(n%2==0&&m%2&&k%2==0&&(n*m-n)/2>=k)?"YES":"NO")<<'\n';}
}
