#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
string x[11],ans;
int n,m;
void ok(string s){
    for(int i=0;i<n;i++){
        int c=0;

        for(int j=0;j<m;j++)
            if(x[i][j]!=s[j])c++;

        if(c>1)return;
    }

    ans=s;
}

void check(string s){
    for(int i=0;i<n;i++){
        if(x[i][s.size()-1]!=s.back()){
            ok(s+string(x[i].begin()+s.size(),x[i].end()));
            return;
        }
    }
}



int main()
{
Ahmed_Sayed();
tt
cin>>n>>m,ans="";
for(int i=0;i<n;i++)cin>>x[i];

string t;
set<char>st;
for(int i=0;i<m;i++){
    int c=0;
    st.clear();

    for(int j=0;j<n;j++)st.insert(x[j][i]);
    if(st.size()>1)break;

    t+=x[0][i];
}

if(t.size()==m)cout<<t;

else{
    for(auto i:st){
        check(t+i);
        if(ans.size())break;
    }

    cout<<(ans.size()?ans:"-1");
}
nn;}
}