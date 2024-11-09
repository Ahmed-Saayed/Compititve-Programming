#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

int main()
{
Ahmed_Sayed();
tt
string s;cin>>s;
vector<int>adj[26];
set<char>st;
for(int i=0;i<s.size();i++){
    adj[s[i]-'a'].push_back(i);
    st.insert(s[i]);
}

int cur=-1;
while(st.size())
    for(int i=25;~i;i--)
        if(adj[i].size()){
            int id=*upper_bound(all(adj[i]),cur);

            bool p=1;
            for(int j=0;j<26&&p;j++)
                if(adj[j].size()&&adj[j].back()<id)p=0;

            if(p){
                cout<<char(i+'a'),
                cur=id,
                adj[i].clear(),
                st.erase(char(i+'a'));
            break;
            }
        }
nn;}
}
