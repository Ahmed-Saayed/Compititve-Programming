#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+1;
struct st{
    ll mn,lazy;
};

ll n,x[N];
st seg[N*4];

void push(int node,int l,int r){
    seg[node].mn+=seg[node].lazy;

    if(l!=r){
        seg[node*2].lazy+=seg[node].lazy,
        seg[node*2+1].lazy+=seg[node].lazy;
    }
    seg[node].lazy=0;
}

void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node].mn=x[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node].mn=min(seg[node*2].mn,seg[node*2+1].mn);
}

ll get(int node,int l,int r,int lef,int righ){
    push(node,l,r);

    if(l>righ||r<lef)return 1e18;
    if(l>=lef&&r<=righ)return seg[node].mn;

    int m=l+r>>1;
    return min(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
}

void up(int node,int l,int r,int lef,int righ,int val){
    push(node,l,r);

    if(l>righ||r<lef)return;
    if(l>=lef&&r<=righ){
        seg[node].lazy+=val;
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
cin>>n;
for(int i=1;i<=n;i++)cin>>x[i];
bul();

int q,lef,righ,val;cin>>q;

cin.ignore();
while(q--){

    string s;getline(cin,s);

    stringstream o(s);
    vector<ll>v;
    ll g;

    while(o>>g)v.push_back(g);

    lef=v[0]+1,righ=v[1]+1;
    if(v.size()==3){
        val=v.back();
        if(lef>righ){
            up(1,1,n,lef,n,val),
            up(1,1,n,1,righ,val);
        }
        else up(1,1,n,lef,righ,val);
    }
    else{
        ll mn;
        if(lef>righ){
            mn=get(1,1,n,lef,n),
            mn=min(mn,get(1,1,n,1,righ));
        }
        else mn=get(1,1,n,lef,righ);
        cout<<mn<<'\n';
    }
}
}
