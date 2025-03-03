#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--) {
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

struct FenwickTree {
    vector<ll> bit;
    int n;
    FenwickTree(){};
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        if(l>r)return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


const int N=1e5+5,sqr=320,r=1e5;
FenwickTree f(N);
struct query{
    int l,r,idblk,idq;

    query(){}

    query(int _l,int _r,int _idq){
        l=_l,r=_r,idq=_idq,idblk=l/sqr;
    }

    bool operator<(const query&q)const{
        if(idblk!=q.idblk)return idblk<q.idblk;

        return r<q.r;
    }
};

query qu[N];
int n,q,x[N],k;
ll ans[N],fre[N],ret;

void add(int id){
    ret+=f.sum(0,x[id]-k-(!k))+f.sum(x[id]+k,1e5);
    f.add(x[id],1);
}

void del(int id){
    f.add(x[id],-1);
    ret-=f.sum(0,x[id]-k-(!k))+f.sum(x[id]+k,1e5);
}

void MOs(){
    sort(qu,qu+q);

    int l=1,r=0;

    for(int i=0;i<q;i++){
        while(l<qu[i].l)del(l++);
        while(l>qu[i].l)add(--l);

        while(r<qu[i].r)add(++r);
        while(r>qu[i].r)del(r--);

        ans[qu[i].idq]=ret;
    }

    for(int i=0;i<q;i++)
        cout<<ans[i]<<'\n';
}

int main()
{
Ahmed_Sayed();
cin>>n>>q>>k;
for(int i=0;i<n;i++)cin>>x[i];
for(int i=0;i<q;i++){
    int l,r;cin>>l>>r;

    qu[i]=query(--l,--r,i);
}
MOs();
}
