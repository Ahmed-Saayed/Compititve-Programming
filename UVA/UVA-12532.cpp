#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

const int N=1e5 + 5;
ll n,x[N],seg[N*4],seg2[N*4],lef,righ,id,val,zero,mins;
void bul(int node=1,int l=1,int r=n){
    if(l==r){
        seg[node]=x[l]<0;
        seg2[node]=!x[l];
        return;
    }

    int m=(l+r)/2;
    bul(node*2,l,m),
    bul(node*2+1,m+1,r);

    seg[node] = seg[node*2] + seg[node*2+1];
    seg2[node] = seg2[node*2] + seg2[node*2+1];
}

void get(int node=1,int l=1,int r=n){
    if(l>righ||r<lef)return;
    if(l>=lef&&r<=righ){
        mins+=seg[node];
        zero+=seg2[node];
        return;
    }

    int m=(l+r)/2;
    get(node*2,l,m),
    get(node*2+1,m+1,r);
}

void up(int node=1,int l=1,int r=n){
    if(l>id||r<id)return;
    if(l==r){
        seg[node]=val<0;
        seg2[node]=!val;
        return;
    }

    int m=(l+r)/2;
    up(node*2,l,m),
    up(node*2+1,m+1,r);

    seg[node] = seg[node*2] + seg[node*2+1];
    seg2[node] = seg2[node*2] + seg2[node*2+1];
}

int main()
{
Ahmed_Sayed();
int q;

while(cin>>n>>q){
for(int i=1;i<=n;i++)cin>>x[i];
bul();

while(q--){
    char c;cin>>c;
    if(c=='C'){
        cin>>id>>val,up();
    }
    else{
        cin>>lef>>righ;
        zero=0,mins=0,get();
        if(zero)cout<<0;
        else cout<<(mins%2?'-':'+');
    }
}
nn;
}
}
