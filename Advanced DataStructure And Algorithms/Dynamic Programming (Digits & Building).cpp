#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){						//509C - Sums of Digits
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

string add(string s){

    if(count(all(s),'9')==s.size())
        return '1'+string(s.size(),'0');
    else{
        int id=s.size()-1;
        while(s[id]=='9')id--;
        s[id]++;
        fill(s.begin()+id+1,s.end(),'0');

        return s;
    }
}

string deletezezo(string s){

    int d=0;
    for(auto i:s)if(i!='0')break;else d++;
    s.erase(s.begin(),s.begin()+d);

    return s;
}

const ll N=301;
int n,x[N],id,dp[400][N][2][2];
string s,t;

int rec(int i=0,int sm=0,int f1=0,int f2=0){
    if(i==s.size()||sm>x[id])return sm==x[id];

    int &ret=dp[i][sm][f1][f2],mn=!f1?s[i]-'0':0,mx=!f2?t[i]-'0':9;
    if(~ret)return ret;

    ret=0;
    for(int j=mn;j<=mx&&!ret;j++)
        ret|=rec(i+1,sm+j,!(!f1&&j==mn),!(!f2&&j==mx));

    return ret;
}

string bul(int i=0,int sm=0,int f1=0,int f2=0){
    if(i==s.size())return "";

    int best=rec(i,sm,f1,f2),mn=!f1?s[i]-'0':0,mx=!f2?t[i]-'0':9;

    for(int j=mn;j<=mx;j++)
        if(best==rec(i+1,sm+j,!(!f1&&j==mn),!(!f2&&j==mx))){
            return char(j+'0')+bul(i+1,sm+j,!(!f1&&j==mn),!(!f2&&j==mx));
        }
}

int main()
{
Ahmed_Sayed();
cin>>n;
t=string(400,'9'),s="0";
for(int i=0;i<n;i++)cin>>x[i];

while(id<n){
    memset(dp,-1,sizeof dp);

    s=add(s);
    s=string(t.size()-s.size(),'0')+s;

    string tmp=bul();

    tmp=deletezezo(tmp);
    cout<<tmp<<'\n';
    s=tmp,id++;
}
}