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
int x[n],mx=0,num;
map<int,int>mp;
for(auto&i:x){
    cin>>i,mp[i]++;

    if(mp[i]>mx)mx=mp[i],num=i;
}

vector<array<int,3>>ans;
for(int i=0;i<n;i++){
    if(x[i]==num){

        while(~(i-1)){
            if(x[i-1]<num)ans.push_back({1,i-1,i});
            else ans.push_back({2,i-1,i});
            i--;
        }
        break;
    }
}
bool p=0;
for(int i=0;i<n-1;i++){
    if(x[i]==num)p=1;

    if(p&&x[i+1]!=num){
        if(x[i+1]<num)ans.push_back({1,i+1,i});
        else ans.push_back({2,i+1,i});
    }
}

cout<<ans.size()<<'\n';
for(auto[a,b,c]:ans)
    cout<<a<<' '<<++b<<' '<<++c<<'\n';
}
