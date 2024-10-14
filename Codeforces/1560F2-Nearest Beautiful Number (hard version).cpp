#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int cnt(int n){
    int ret=0;
    while(n)ret++,n&=n-1;
    return ret;
}

string s;
int k,dp[11][1<<10][2];
int rec(int i=0,int mask=0,bool p=0){
    if(cnt(mask)>k)return 0;
    if(i==s.size())return 1;

    int&ret=dp[i][mask][p];
    if(~ret)return ret;

    ret=0;

    int mn=!p?s[i]-'0':0;
    for(int j=mn;j<=9;j++){
        ret|=rec(i+1,mask|(1<<j),!(!p&&j==mn));
        if(ret)break;
    }

    return ret;
}

void bul(int i=0,int mask=0,bool p=0){
    if(i==s.size())return;

    int best=rec(i,mask,p);

    int mn=!p?s[i]-'0':0;
    for(int j=mn;j<=9;j++)
        if(best==rec(i+1,mask|(1<<j),!(!p&&j==mn))){
            cout<<j;
            return bul(i+1,mask|(1<<j),!(!p&&j==mn));
        }
}

int main()
{
Ahmed_Sayed();
tt
cin>>s>>k;
memset(dp,-1,sizeof dp);

bul();nn;}
}