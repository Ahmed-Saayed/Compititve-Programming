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
int n;cin>>n;
int fre[(ll)2e5+5]{};

while(n--){
    int o;cin>>o,fre[o]++;
}

vector<int>ans,v;

for(int i=1;i<=2e5+1;i++){
    if(!v.size())
        for(int j=0;j<fre[i];j++)v.push_back(i);
    else
        for(int j=0;j<fre[i]-1;j++)v.push_back(i);

    if(!fre[i]||(fre[i]==1&&i!=v[0])){

        if(fre[i]||(v.size()&&v.back()!=v[0])){
            v.push_back(fre[i]?i:v.back());

            set<int>s;
            for(auto i:v)s.insert(i);
            s.erase(*s.rbegin());
            s.erase(s.begin());

            vector<int>tmp;
            for(auto i:s)tmp.push_back(i);
            for(int i=tmp.size()-1;~i;i--)v.push_back(tmp[i]);
        }

        if(v.size()>ans.size())ans=v;
        v.clear();
        if(fre[i])v={i};
    }
}

cout<<ans.size()<<'\n';
for(auto i:ans)cout<<i<<' ';
}