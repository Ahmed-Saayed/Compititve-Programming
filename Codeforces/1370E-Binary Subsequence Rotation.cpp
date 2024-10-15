#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int main()
{
Ahmed_Sayed();
int n,c=0,c2=0,mx=0;cin>>n;
string s,t;cin>>s>>t;
map<char,int>mp1,mp2;
for(auto i:s)mp1[i]++;
for(auto i:t)mp2[i]++;

if(mp1['0']!=mp2['0']||mp1['1']!=mp2['1']){cout<<-1;return 0;}

for(int i=0;i<n;i++){
    if(s[i]!=t[i]){
        if(s[i]=='1')c++;
        else if(c)c--;
        if(s[i]=='0')c2++;
        else if(c2)c2--;
        mx=max({mx,c,c2});
    }
}
cout<<mx;
}