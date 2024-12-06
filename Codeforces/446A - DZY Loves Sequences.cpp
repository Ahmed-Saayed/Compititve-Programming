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
int n;cin >> n;
int x[n + 2]{}, pre[n + 2]{}, suf[n + 2]{}, c = 0;
for(int i = 1 ;i <= n ;i++){
    cin >> x[i];
    if(x[i] > x[i - 1])c++;
    else c = 1;

    pre[i] = c;
}

x[n + 1] = 9e9, x[0] = -1, c = 0;
for(int i = n ;i; i--){
    if(x[i] < x[i + 1])c++;
    else c = 1;

    suf[i] = c;
}

int ans = 0;
for(int i = 1 ;i <= n ;i++){
    ans = max(ans, pre[i] + (x[i + 1] > x[i]) * suf[i + 1]);
    ans = max(ans, max(pre[i - 1], suf[i + 1]) + 1);

    if(x[i - 1] + 1 < x[i + 1])
        ans = max(ans, pre[i - 1] + 1 + suf[i + 1]);
}

cout << ans;
}
