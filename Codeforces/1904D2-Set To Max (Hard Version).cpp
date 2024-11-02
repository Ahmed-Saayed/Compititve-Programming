#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
int seg[(ll)1e6];
void bul(int node,int l,int r,int x[]){
    if(l==r){
        seg[node]=x[l];
        return;
    }

    int m=l+r>>1;
    bul(node*2,l,m,x),
    bul(node*2+1,m+1,r,x);

    seg[node]=max(seg[node*2],seg[node*2+1]);
}

int get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node];

    int m=l+r>>1;
    return max(get(node*2,l,m,lef,righ),get(node*2+1,m+1,r,lef,righ));
}

void up(int node,int l,int r,int id,int val){
    if(l>id||r<id)return;
    if(l==r){
        seg[node]=val;
        return;
    }

    int m=l+r>>1;
    up(node*2,l,m,id,val),
    up(node*2+1,m+1,r,id,val);

    seg[node]=max(seg[node*2],seg[node*2+1]);
}

int main()
{
Ahmed_Sayed();
tt
int n,ans=1;cin>>n;

fill(seg,seg+n*4+5,0);

int a[n+1],b[n+1];
vector<pair<int,int>>v;
vector<int>mp[n+1];
set<int>idess{0,n+1};

for(int i=1;i<=n;i++)
    cin>>a[i],idess.insert(i);

for(int i=1;i<=n;i++){
    cin>>b[i],mp[b[i]].push_back(i);

    if(b[i]!=a[i]){
        if(b[i]<a[i])ans=0;
        else v.push_back({b[i],i});
    }
}

if(!ans){cout<<"NO\n";continue;}

bul(1,1,n,a);
sort(all(v));

int cnt=1;
set<int>s{0,n+1};
for(auto i:v){
    auto[mx,indx]=i;
    if(a[indx]==b[indx])continue;

    while(cnt<mx){
        for(auto i:mp[cnt])s.insert(i);
        cnt++;
    }

    auto it=s.upper_bound(indx),it2=it;
    it2--;

    int l=indx,r=*it-1,m,id1=-1,id2;
    while(l<=r){
        m=l+r>>1;

        (get(1,1,n,indx,m)>mx?r=m-1:l=m+1);
    }
    if(r>=indx&&get(1,1,n,indx,r)==mx)id1=indx,id2=r;

    if(id1==-1){
        l=*it2+1,r=indx;
        while(l<=r){
            m=l+r>>1;

            (get(1,1,n,m,indx)>mx?l=m+1:r=m-1);
        }

        if(l<=indx&&get(1,1,n,l,indx)==mx)id1=l,id2=indx;
    }

    if(~id1){
        auto i=idess.lower_bound(id1);

        while(*i<=id2){
            a[*i]=mx,up(1,1,n,*i,mx);
            i=idess.erase(i);
        }
    }
    else{
        ans=0;break;
    }
}

cout<<(ans?"YES":"NO")<<'\n';}
}
