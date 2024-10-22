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
tt
ll n,s;cin >> n >> s;
ll pre[n + 1]{};

for(int i = 1;i <= n ;i++)
    cin >> pre[i], pre[i] += pre[i - 1];

int lef = -1,righ = -1, mx = 0, o = 1;
for(int i = 1 ;i <= n; i++){
    while(o <= i && pre[i] - pre[o - 1] + s < 0)o++;

    if(i - o + 1 > mx)
        mx = i - o + 1,lef = o, righ = i;
}

if(!mx)cout << -1;
else cout << lef << ' ' << righ;
nn;}
}
