#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
string conv(ll n){
    string ret;

    while(n)
        ret += n % 2 + '0', n /= 2;

    reverse(all(ret));
    return ret;
}

int main()
{
Ahmed_Sayed();
ll x,y;cin >> x >> y;

string a = conv(x),b = conv(y);

queue<string>q;
q.push(a);
bool ans = 0;
map<string,bool>vis;

while(q.size()){
    string node = q.front();q.pop();

    int i = 0;
    while(node[i] == '0')i++;
    node.erase(node.begin(),node.begin() + i);

    if(node.size() > b.size() && node[0] == node.back() && node.back() == '1')continue;

    if(node == b){ans = 1;break;}

    string o = node + '0',o2 = node + '1';
    reverse(all(o)),reverse(all(o2));

    if(!vis[o])vis[o] = 1, q.push(o);
    if(!vis[o2])vis[o2] = 1, q.push(o2);
}

cout<<(ans?"YES":"NO");
}
