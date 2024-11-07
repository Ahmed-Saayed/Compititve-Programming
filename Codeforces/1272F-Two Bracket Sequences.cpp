#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
string s,t;
int dp[500][201][201];
int rec(int open=0,int i=0,int j=0){
    if(i==s.size()&&j==t.size()||open==s.size()+t.size())return open;

    int&ret=dp[open][i][j];
    if(~ret)return ret;

    ret=1+rec(open+1,i+(i<s.size()&&s[i]=='('),j+(j<t.size()&&t[j]=='('));

    if(open)
        ret=min(ret,1+rec(open-1,i+(i<s.size()&&s[i]==')'),j+(j<t.size()&&t[j]==')')));

    return ret;
}

string bul(int open=0,int i=0,int j=0){
    if(i==s.size()&&j==t.size())
        return string(open,')');

    int best=rec(open,i,j);
    if(best==1+rec(open+1,i+(i<s.size()&&s[i]=='('),j+(j<t.size()&&t[j]=='(')))
            return '('+bul(open+1,i+(i<s.size()&&s[i]=='('),j+(j<t.size()&&t[j]=='('));

    if(open&&best==1+rec(open-1,i+(i<s.size()&&s[i]==')'),j+(j<t.size()&&t[j]==')')))
            return ')'+bul(open-1,i+(i<s.size()&&s[i]==')'),j+(j<t.size()&&t[j]==')'));
}

int main()
{
Ahmed_Sayed();
cin>>s>>t,
memset(dp,-1,sizeof dp);

cout<<bul();
}