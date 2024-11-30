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
int n,d;
string s;cin>>n>>d>>s;
for(int i=n-1;~i;i--){
    if(s[i]=='@'&&d)d--,s[i]='.';
}

cout<<s;
}
