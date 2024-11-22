#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

pair<int,string>calc(string s,string pat,int m){
    string sub=string(s.begin(),s.begin()+m),check;

    for(auto i:pat){
        check+=sub;

        string tmp;
        for(auto j:sub)
            if(j!=i)tmp+=j;

        sub=tmp;
    }

    return {check.size(),check};
}

int main()
{
Ahmed_Sayed();
tt
string s,pat;cin>>s;
int vis[26]{};
for(int i=s.size()-1;~i;i--){
    if(!vis[s[i]-'a'])
        pat+=s[i],vis[s[i]-'a']=1;
}
reverse(all(pat));

int l=1,r=s.size(),m;
while(l<=r){
    m=l+r>>1;

    (calc(s,pat,m).first<=s.size()?l=m+1:r=m-1);
}

if(calc(s,pat,r).second==s)
    cout<<string(s.begin(),s.begin()+r)<<' '<<pat;
else
    cout<<-1;

nn;}
}
