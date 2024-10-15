#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

struct Trie{

        Trie*ch[26];
        int out;

        Trie(){
            out=0,
            memset(ch,0,sizeof ch);
        }

    void in(string s){

        Trie *cur=this;
        for(auto i:s){
            int id=i-'a';

            if(cur->ch[id]==0)
                cur->ch[id]=new Trie();

            cur=cur->ch[id];
        }
        cur->out++;
    }

    bool cnt(string s){

        Trie *cur=this;
        for(auto i:s){
            int id=i-'a';

            if(cur->ch[id]==0)return 0;
            cur=cur->ch[id];
        }
        return cur->out;
    }
};

int n,dp[(ll)1e4+4];string s;
Trie *tr = new Trie();
int rec(int i=0){
    if(i==n)return 0;

    int&ret=dp[i];
    if(~ret)return ret;

    ret=rec(i+1);

    auto cur=tr;
    for(int j=i;j<n;j++){
        if(cur->ch[s[j]-'a']==0)break;
        cur=cur->ch[s[j]-'a'];

        if(cur->out)
            ret=max(ret,j-i+1+rec(j+1));
    }
    return ret;
}

vector<string>ans;
map<string,string>mp;
void bul(int i=0){
    if(i==n)return;

    int best=rec(i);
    if(best==rec(i+1))return bul(i+1);

    auto cur=tr;
    string t;
    for(int j=i;j<n;j++){
        if(cur->ch[s[j]-'a']==0)break;
        cur=cur->ch[s[j]-'a'],t+=s[j];

        if(cur->out&&best==j-i+1+rec(j+1)){
            ans.push_back(mp[t]);
            return bul(j+1);
        }
    }
}

int main()
{
Ahmed_Sayed();
cin>>n>>s,reverse(all(s));
memset(dp,-1,sizeof dp);

int q;cin>>q;
while(q--){
    string o,tmp;cin>>o,tmp=o;
    for(auto&j:o)j=tolower(j);

    tr->in(o),
    mp[o]=tmp;
}

bul();
reverse(all(ans));
for(auto i:ans)cout<<i<<' ';
}