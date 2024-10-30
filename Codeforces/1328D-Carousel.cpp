#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5;
int n,x[N],dp[N][4][4][4];
int rec(int i=0,int prev=0,int st=0,int mx=0){
    if(i==n)return (x[n-1]!=x[0]&&st==prev?1e9:mx);

    int&ret=dp[i][prev][st][mx];
    if(~ret)return ret;

    ret=1e9;

    for(int j=1;j<=3;j++){
        if(i&&j==prev&&x[i]!=x[i-1])continue;

        ret=min(ret,rec(i+1,j,(!i?j:st),max(mx,j)));
    }
    return ret;
}

string bul(int i=0,int prev=0,int st=0,int mx=0){
    if(i==n)return "";

    int best=rec(i,prev,st,mx);

    for(int j=1;j<=3;j++){
        if(i&&j==prev&&x[i]!=x[i-1])continue;

        if(best==rec(i+1,j,(!i?j:st),max(mx,j)))
            return char(j+'0')+bul(i+1,j,(!i?j:st),max(mx,j));
    }
}

int main()
{
Ahmed_Sayed();
tt
cin>>n;
for(int i=0;i<n;i++)
    memset(dp[i],-1,sizeof dp[i]);

for(int i=0;i<n;i++)cin>>x[i];
string ans=bul();

cout<<*max_element(all(ans))<<'\n';
for(auto i:ans)cout<<i<<' ';
nn;}
}
