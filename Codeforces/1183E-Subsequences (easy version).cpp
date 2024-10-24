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
ll n,k,ans=0;
string s;cin>>n>>k>>s;
set<string>st;

queue<string>q;
q.push(s);
while(q.size()&&st.size()<k){
    string node=q.front();q.pop();
    st.insert(node);

    for(int i=0;i<node.size();i++){
        string t=string(node.begin(),node.begin()+i)+string(node.begin()+i+1,node.end());

        if(st.find(t)==st.end()&&st.size()<k)
            st.insert(t),q.push(t),ans+=n-t.size();
    }
}

cout<<(st.size()==k?ans:-1);
}