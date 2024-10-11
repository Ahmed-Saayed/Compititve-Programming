#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
string s,ans;char f=' ';
int dp[1001][1001];
int rec(int i=0,int j=s.size()-1){
    if(i>=j)return 0;

    int&ret=dp[i][j];
    if(~ret)return ret;

    if(s[i]==s[j])ret=rec(i+1,j-1);
    else ret=min(1+rec(i+1,j),1+rec(i,j-1));
    return ret;
}

void bul(string t="",ll i=0,ll j=s.size()-1){
    if(i>=j){
    if(i==j)f=s[i];
    ans=t;
    return;
    }

    if(s[i]==s[j])bul(t+s[i],i+1,j-1);
    else{
        if(rec(i+1,j)<=rec(i,j-1))bul(t+s[i],i+1,j);
        else bul(t+s[j],i,j-1);
    }
}

int main()
{
Ahmed_Sayed();
while(cin>>s){
f=' ';
memset(dp,-1,sizeof dp);

bul();
cout<<rec()<<' '<<ans;
if(f!=' ')cout<<f;
reverse(all(ans));
cout<<ans;nn;}
}
