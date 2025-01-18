#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5;
int n,dp[N][4];
string s;
int rec(int i=0,int prev=0){
    if(i==s.size())return 0;

    int&ret=dp[i][prev];
    if(~ret)return ret;

    ret=0;

    if(s[i]=='R'){
        if(prev!=2)ret=1+rec(i+1,2);
        if(prev!=1)ret=max(ret,rec(i+1,1));
    }
    else if(s[i]=='P'){
        if(prev!=3)ret=1+rec(i+1,3);
        if(prev!=2)ret=max(ret,rec(i+1,2));
    }
    else{
        if(prev!=1)ret=1+rec(i+1,1);
        if(prev!=3)ret=max(ret,rec(i+1,3));
    }

    return ret;
}

int main()
{
Ahmed_Sayed();
cin>>n>>s;
memset(dp,-1,sizeof dp);
cout<<rec();
}
