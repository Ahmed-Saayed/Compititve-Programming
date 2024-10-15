#include <bits/stdc++.h>
#define ll long long
#define tt int t;cin>>t;while(t--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

bool valid(char c){
    return (c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9');
}

int n,m,dp[200][200];
string s[200],name[200],user[200],text[200];
map<string,ll>mp;
set<ll>v[200];

bool rec(int i=1,int prev=0){
    if(i>m)return 1;

    int &ret=dp[i][prev];
    if(~ret)return ret;

    ret=0;
    if(s[i][0]!='?'){
        if(mp[name[i]]==prev)return 0;
        ret|=rec(i+1,mp[name[i]]);
    }
    else
        for(int j=1;j<=n;j++)if(j!=prev&&v[i].find(j)==v[i].end())ret|=rec(i+1,j);

    return ret;
}

void bul(int i=1,int prev=0){
    if(i>m)return;

    int best=rec(i,prev);

    if(s[i][0]!='?')cout<<name[i]<<text[i]<<'\n',bul(i+1,mp[name[i]]);

    else
        for(int j=1;j<=n;j++)if(j!=prev&&v[i].find(j)==v[i].end()&&best==rec(i+1,j)){
            cout<<user[j]<<text[i]<<'\n';
            return bul(i+1,j);
    }
}


int main()
{
Ahmed_Sayed();
tt
mp.clear();

cin>>n;

for(int i=1;i<=n;i++){
    cin>>user[i],mp[user[i]]=i;
}

cin>>m;
cin.ignore();

for(int i=0;i<=m;i++)for(int j=0;j<=n;j++)dp[i][j]=-1,v[i].clear();

for(int i=1;i<=m;i++){
    string username,k;getline(cin,s[i]);
    bool p=0;
    for(auto j:s[i]){
        if(j==':')p=1;
    
        if(!p)username+=j;
        else k+=j;
    }
    
    text[i]=k;
    name[i]=username;

    if(username=="?"){
        for(int j=0;j<s[i].size();j++){
            if(!valid(s[i][j])) {
                username="";
                for(int k=j+1;k<s[i].size()&&valid(s[i][k]);k++)username+=s[i][k];
                if(mp.find(username)!=mp.end())v[i].insert(mp[username]);
            }
        }
    }
}

bool ok=rec();
if(!ok)cout<<"Impossible\n";
else bul();
}
}