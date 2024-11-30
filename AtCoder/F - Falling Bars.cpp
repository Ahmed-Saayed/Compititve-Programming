#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
struct st{
    int mn,lazy;
};

const int N=2e5+5;
st seg[N*4];
vector<int>mxcell;

void bul(int node,int l,int r){
    if(l==r){
        seg[node].mn=mxcell[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node].mn=min(seg[node*2].mn,seg[node*2+1].mn);
}

void push(int node,int l,int r){
    if(!seg[node].lazy)return;

    seg[node].mn=seg[node].lazy;
    if(l!=r){
       seg[node*2].lazy=seg[node].lazy,
       seg[node*2+1].lazy=seg[node].lazy;
    }

    seg[node].lazy=0;
}

int get(int node,int l,int r,int lef,int righ){
    push(node,l,r);
    if(l>righ||r<lef)return 1e9;
    if(l>=lef&&r<=righ)return seg[node].mn;

    int m=l+r>>1;
    return min(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
}

void up(int node,int l,int r,int lef,int righ,int val){
    push(node,l,r);
    if(l>righ||r<lef)return;
    if(l>=lef&&r<=righ){
        seg[node].lazy=val;
        push(node,l,r);
        return;
    }

    int m=l+r>>1;
    up(node*2,l,m,lef,righ,val),
    up(node*2+1,m+1,r,lef,righ,val);

    seg[node].mn=min(seg[node*2].mn,seg[node*2+1].mn);
}

int main()
{
Ahmed_Sayed();
int h,w,n;cin>>h>>w>>n;
array<ll,4>x[n];
for(int i=0;i<n;i++){
    cin>>x[i][0]>>x[i][1]>>x[i][2],x[i][3]=i;
}

sort(x,x+n),reverse(x,x+n);
mxcell=vector<int>(w+1,h+1);
bul(1,1,w);

vector<int>ans(n);
for(auto[a,b,c,d]:x){
    int mx=get(1,1,w,b,b+c-1);

    mx--;
    up(1,1,w,b,b+c-1,mx);

    ans[d]=mx;
}

for(auto i:ans)cout<<i<<'\n';
}
