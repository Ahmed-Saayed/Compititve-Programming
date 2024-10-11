#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

double dis(int x,int x2,int y,int y2){
    return hypot(x-x2,y-y2);
}

int n,x[20],y[20];
double dp[1<<17];

double rec(int mask=0){
    if(mask==(1<<n)-1)return 0;

double &ret=dp[mask];
if(ret==ret)return ret;

ret=1e7;
for(int i=0;i<n;i++){
    if((mask>>i)&1)continue;

    for(int j=i+1;j<n;j++){
        if((mask>>j)&1)continue;
            ret=min(ret,dis(x[i],x[j],y[i],y[j])+rec(mask|(1<<j)|(1<<i)));
    }
}
return ret;
}

int main()
{
Ahmed_Sayed();
int t=1;
while(cin>>n&&n){
n*=2;
string s;
for(int i=0;i<n;i++)cin>>s>>x[i]>>y[i];
memset(dp,-1,sizeof dp);

cout<<"Case "<<t++<<": "<<fixed<<setprecision(2)<<rec();
nn;}
}
