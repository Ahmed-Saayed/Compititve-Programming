#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const int N=2e5+5;
int sqr;
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
ll n,q,x[N],fre[1ll<<((ll)log2(1e6)+1)],ans[N],ret,k;

void add(int id){
    ret+=fre[id^k];
    fre[id]++;
}

void del(int id){
    fre[id]--;
    ret-=fre[id^k];
}

void MOs(){
    sort(qu,qu+q);

    int l=1,r=0;

    for(int i=0;i<q;i++){
        while(l<qu[i].l)del(x[l++]);
        while(l>qu[i].l)add(x[--l]);

        while(r<qu[i].r)add(x[++r]);
        while(r>qu[i].r)del(x[r--]);

        ans[qu[i].idq]=ret;
    }

    for(int i=0;i<q;i++)
        cout<<ans[i]<<'\n';
}

int main()
{
Ahmed_Sayed();
cin>>n>>q>>k,sqr=sqrt(n)+5;
for(int i=1;i<=n;i++)
    cin>>x[i],x[i]^=x[i-1];

for(int i=0;i<q;i++){
    int l,r;cin>>l>>r;

    qu[i]=query(--l,r,i);
}
MOs();
}
