#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

class Solution {
public:
string clearStars(string s) {

vector<int>on(s.size());
map<char,vector<int>>mp;

for(int i=0;i<s.size();i++){
    if(s[i]=='*'){
        on[i]=1;
        on[mp.begin()->second.back()]=1;
        mp.begin()->second.pop_back();
    }
    else mp[s[i]].push_back(i);
    while(mp.size()&&!mp.begin()->second.size())
        mp.erase(mp.begin());
}

string ans;
for(int i=0;i<s.size();i++)
    if(!on[i])ans+=s[i];
return ans;              
}
};