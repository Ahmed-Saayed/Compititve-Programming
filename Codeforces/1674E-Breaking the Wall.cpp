#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int Mx(int a,int b){
    return max((max(a,b)+1)/2,(a+b+2)/3);
}

int calc(int a,int b,int c){
    int ret=a%2==c%2&&a%2?a/2+c/2+1:(a+1)/2+(c+1)/2;
    return min({ret,Mx(a,b),Mx(b,c)});
}

int main()
{
Ahmed_Sayed();
int n;cin>>n;
int x[n];
for(auto&i:x)cin>>i;

int ans=min(Mx(x[0],x[1]),Mx(x[n-1],x[n-2]));
for(int i=1;i<n-1;i++){
    ans=min(ans,calc(x[i-1],x[i],x[i+1]));
}

sort(x,x+n);
ans=min(ans,(x[0]+1)/2+(x[1]+1)/2);

cout<<ans;
}