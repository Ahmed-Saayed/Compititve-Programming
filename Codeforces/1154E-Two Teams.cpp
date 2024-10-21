#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N = 2e5 + 5;
int seg[N*4], x[N], ans[N];
set<int>s;
int op, lef, righ, n;

void bul(int node = 1,int l = 1,int r = n){
    if(l == r){
        seg[node] = 1;
        return;
    }

    int m = l + r >> 1;

    bul(node * 2, l, m),
    bul(node * 2 + 1, m + 1, r);

    seg[node] = seg[node*2] + seg[node*2+1];
}

void up(int node = 1,int l = 1,int r = n){
    if(l > righ || r < lef || !seg[node])return ;
    if(l == r){
        s.erase(x[l]),
        seg[node] = 0;
        ans[l] = op;

        return;
    }

    int m = l + r >> 1;

    up(node * 2, l, m),
    up(node * 2 + 1 ,m+1, r);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int get(int node,int l,int r,int lef,int righ){
    if(l > righ || r < lef)return 0;
    if(l >= lef && r <= righ)return seg[node];

    int m= l + r >> 1;
    return get(node * 2, l, m, lef, righ)+get(node * 2 + 1 , m + 1, r, lef , righ);
}

int main()
{
Ahmed_Sayed();
int k ;cin >> n >> k;
bul();

int id[n + 1];
for(int i = 1;i <= n; i++)
    cin >> x[i], id[x[i]] = i, s.insert(x[i]);

int c = 0;
while(s.size()){
    int idx = id[*s.rbegin()];

    op = c + 1;

    int l2 = idx + 1,r2 = n, m;
    while(l2 <= r2){
        m= l2 + r2 >> 1;

        (get(1, 1, n, idx + 1, m) > k ? r2 = m - 1 : l2 = m + 1);
    }

    lef = idx, righ = r2, up();

    l2 = 1, r2 =idx - 1, m;
    while(l2 <= r2){
        m = l2 + r2 >> 1;

        (get(1, 1, n, m, idx-1) > k ? l2 = m + 1 : r2 = m - 1);
    }

    lef = l2, righ = idx - 1, up();

    c= (c + 1) % 2;
}

for(int i = 1 ;i <= n; i++)cout << ans[i];
}
