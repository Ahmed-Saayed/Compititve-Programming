#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    }
int main()
{
Ahmed_Sayed();
int n;cin>>n;
stack<int>s;
ll x[n],c=0;
for(auto &i:x)cin>>i;
for(int i=0;i<n;i++){
    c++;
    if((x[i]%2!=x[i+1]%2||i==n-1)&&c%2!=0){
        if(x[i]%2==0){
            if(s.size()&&s.top()==2)s.pop();
            else s.push(2);
        }
        else{
            if(s.size()&&s.top()==1)s.pop();
            else s.push(1);
        }
        c=0;
    }
}
if(s.size()>1)cout<<"NO";else cout<<"YES";
}