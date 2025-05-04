#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=1e5+5;

struct st{
    int lazy,zero,one,two;
};
st seg[N*4];

void push(int node,int l,int r){

    int a=seg[node].zero,b=seg[node].one,c=seg[node].two;
    if(seg[node].lazy%3==1)
        seg[node].zero=c,
        seg[node].one=a,
        seg[node].two=b;

    if(seg[node].lazy%3==2)
        seg[node].zero=b,
        seg[node].one=c,
        seg[node].two=a;


    if(l!=r){
        seg[node*2].lazy+=seg[node].lazy,
        seg[node*2+1].lazy+=seg[node].lazy;
    }

    seg[node].lazy=0;
}

void merge(int node){
    seg[node].zero = seg[node*2].zero + seg[node*2+1].zero;
    seg[node].one = seg[node*2].one + seg[node*2+1].one;
    seg[node].two = seg[node*2].two + seg[node*2+1].two;
}

void build(int node,int l,int r){
    if(l==r){
        seg[node].zero=1;
        return;
    }

    int m=l+r>>1;
    build(node*2,l,m),
    build(node*2+1,m+1,r);

    merge(node);
}

int get(int node,int l,int r,int lef,int righ){
    push(node,l,r);

    if(l>righ||r<lef)
        return 0;

    if(l>=lef&&r<=righ)
        return seg[node].zero;

    int m=l+r>>1;
    return get(node*2,l,m,lef,righ) + get(node*2+1,m+1,r,lef,righ);
}

void update(int node,int l,int r,int lef,int righ){
    push(node,l,r);

    if(r<lef||l>righ)return;
    if(l>=lef&&r<=righ){
        seg[node].lazy++;
        push(node,l,r);

        return;
    }

    int m=l+r>>1;
    update(node*2,l,m,lef,righ),
    update(node*2+1,m+1,r,lef,righ);

    merge(node);
}

int main()
{
Ahmed_Sayed();
int n,q;cin>>n>>q;
build(1,1,n);

while(q--){
    int type,l,r;cin>>type>>l>>r,l++,r++;
    if(!type)
        update(1,1,n,l,r);
    else
        cout<<get(1,1,n,l,r)<<'\n';
}
}
