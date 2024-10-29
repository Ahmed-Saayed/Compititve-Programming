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
string s,t;cin>>s>>t,s='*'+s;
int pre[s.size()+5]{},suf[s.size()+5]{},o=0;

for(int i=1;i<s.size();i++){
    if(o<t.size()&&s[i]==t[o])o++;

    pre[i]=o;
}

o=t.size()-1;
for(int i=s.size()-1;i;i--){
    if(~o&&s[i]==t[o])o--;

    suf[i]=t.size()-1-o;
}

int l=1,r=s.size(),m;
while(l<=r){
    m=l+r>>1;
    bool p=0;

    for(int i=1;i+m-1<s.size() && !p;i++)
        if(pre[i-1]+suf[i+m]>=t.size())p=1;

    (p?l=m+1:r=m-1);
}

cout<<r;
}