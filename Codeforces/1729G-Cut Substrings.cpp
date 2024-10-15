#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=501,mod=1e9+7;
ll up[N],dp[N],dp2[N][N],ans;

int add(int a,int b){
    ll ret=a+b;
    if(ret>mod)ret-=mod;

    return ret;
}

string s,t;
ll rec(int i=0){
    if(i==s.size())return 0;

    ll&ret=dp[i];
    if(~ret)return ret;

    ret=1e9;

    if(!up[i])return ret=rec(i+1);

    for(int j=i;j<i+t.size();j++)
        if(up[j])ret=min(ret,1+rec(j+t.size()));

    return ret;
}

ll rec2(int i=0,int cnt=0){
    if(i==s.size())return cnt==ans;

    ll&ret=dp2[i][cnt];
    if(~ret)return ret;

    ret=0;

    if(!up[i])return ret=add(ret,rec2(i+1,cnt));

    for(int j=i;j<i+t.size();j++)
        if(up[j])ret=add(ret,rec2(j+t.size(),cnt+1));

    return ret;
}

int main()
{
Ahmed_Sayed();
tt
cin>>s>>t;
fill(up,up+s.size(),0);
fill(dp,dp+s.size(),-1);

for(int i=0;i<s.size();i++)
    for(int j=0;j<s.size();j++)dp2[i][j]=-1;

for(int i=0;i<s.size();i++)
    if(s.substr(i,t.size())==t)up[i]=1;

ans=rec();
cout<<ans<<' '<<rec2()<<'\n';}
}