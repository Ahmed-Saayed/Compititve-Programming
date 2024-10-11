#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int n,a,b,dp[40][40][40][40];
string s;
int rec(int i=0,int facta=0,int factb=0,int cnt=0){
    if(i==n)return (cnt&&cnt!=n&&!facta&&!factb?abs(n-cnt-cnt):1e9);

    int&ret=dp[i][facta][factb][cnt];
    if(~ret)return ret;

    ret=rec(i+1,facta,(factb*10+s[i]-'0')%b,cnt);

    return ret=min(ret,rec(i+1,(facta*10+s[i]-'0')%a,factb,cnt+1));
}

void bul(int i=0,int facta=0,int factb=0,int cnt=0){
    if(i==n)return;

    int best=rec(i,facta,factb,cnt);

    if(best==rec(i+1,facta,(factb*10+s[i]-'0')%b,cnt)){
        cout<<'B';
        return bul(i+1,facta,(factb*10+s[i]-'0')%b,cnt);
    }

    cout<<'R';
    bul(i+1,(facta*10+s[i]-'0')%a,factb,cnt+1);
}

int main()
{
Ahmed_Sayed();
tt
cin>>n>>a>>b>>s;
memset(dp,-1,sizeof dp);

int ans=rec();
if(ans==1e9)cout<<-1;
else bul();
nn;}
}