(Mother Library)
#include <bits/stdc++.h>

//=========================================================================
(Fast Code)
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//=========================================================================
(Fast Power)
ll fp(ll x, ll k,ll mod){
	ll ret = 1;
	x%=mod;
	while (k){
		if (k & 1) ret = (ret%mod*x) % mod;
		k >>= 1; x = (x*x) % mod;
	}
	return ret%mod;
}

//=========================================================================
(Npr, Ncr ,Factorial ,mod Inv, Fast power)
struct Combinatorics{
    vector<ll>fact,inv;
    ll mod;

    Combinatorics(){}

    Combinatorics(int n,int mod){
        fact=inv=vector<ll>(n+1);
        fact[0]=inv[0]=1,
        this->mod=mod;

        for(ll i=1;i<=n;i++){
            fact[i] = fact[i-1] * i % mod;
            inv[i]=fp(fact[i],mod-2);
        }
    }

    ll fp(ll x, ll k){
        ll ret = 1;
        x%=mod;
        while (k){
            if (k & 1) ret = (ret%mod*x) % mod;
            k >>= 1; x = (x*x) % mod;
        }

        return ret%mod;
    }


    ll fix(ll x){return (x%mod+mod)%mod;}

    ll ncr(ll n,ll r){
          if(r>n)return 0;
          return (fact[n]*inv[r])%mod*inv[n-r]%mod;
    }

    ll npr(ll n,ll r){
          if(r>n)return 0;
          return fact[n]*inv[n-r]%mod;
    }
};

//=========================================================================
(String mod)
int mod(string s, int a){
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = (res * 10 + s[i] - '0') % a;
 
    return res;
}

//=========================================================================
(partial Sum On Grid)

arr[a][b]     += val
arr[c+1][b]   -= val
arr[a][d+1]   -= val
arr[c+1][d+1] += val

//=========================================================================
(Some math law)

ll sum(ll n){
return n*(n+1)/2;
}
// summation fron 1 to n

ll dis=x[c][d]-x[a-1][d]-x[c][b-1]+x[a-1][b-1];
// sub 2D array summation 

(sum(all(arr))^2
-sum(x[i]^2)/2 1<=i<=n
//summation of multiply each pair in array
	
(summation all odd number from L to R)
(y+1)/2*((y+1)/2)-(x+1)/2*((x+1)/2) 
//
(summation all even number from L to R)
(y+2)/2)*(y/2)-(x+2)/2*(x/2)
//
(summation number from 1 to n that is divisable by x)
sum(n/x)*x
//
original price befor disc
(current price/(1-(disc%)))
//	
rotate matrix 90 degree  x[j][n-1-i];
rotate matrix 180 degree x[n-1-i][n-1-j];
rotate matrix 270 degree x[n-1-j][i];
//
bool Check(double circle_x, double circle_y,double rad, double x, double y){
    double dis=sqrt(pow(x - circle_x,2)+pow(y - circle_y,2));

    //return dis<rad;  point strictly inside circle 
    //return dis==rad;  point strictly on circle 
    //return dis>rad;  point strictly out circle 
}
//
int circle(int x1, int y1, int x2, int y2, int r1, int r2)
{
    double d = sqrt((x1 - x2) * (x1 - x2)
                         + (y1 - y2) * (y1 - y2));

    if (d <= r1 - r2) {
        cout << "Circle B is inside A";
    }
    else if (d <= r2 - r1) {
        cout << "Circle A is inside B";
    }
    else if (d < r1 + r2) {
        cout << "Circle intersect to each other";
    }
    else if (d == r1 + r2) {
        cout << "Circle touch to each other";
    }
    else {
        cout << "Circle not touch to each other";
    }
}
//
v is vector<pair<int,int>>  have 4 elements cordinates of the points rectangle
sort(all(v))

bool check_point_inside_rec(vector<pair<int,int>>v,pair<int,int>p){
    return p.first>=v[0].first&&p.first<=v.back().first&&p.second>=v[0].second&&p.second<=v[1].second;
}

bool check_has_edges_parallel_to_the_axes(vector<pair<int,int>>v){
    return v[0].first==v[1].first&&v[2].first==v[3].first&&v[0].second==v[2].second&&v[1].second==v[3].second;
}

int calc_area_rec(vector<pair<int,int>>v){
    return abs(v[1].second-v[0].second)*abs(v[1].first-v[2].first);
}

// there are NCr ways to make this choice. Find the sum of f(S)
// f(S) over all those ways where f(S) = set of integers f(X)=max(X)−min(X)..

sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        ans=fix(ans-ncr(n-i-1,k-1)*v[i]);
        ans=fix(ans+ncr(i,k-1)*v[i]);
    }

//=========================================================================
(Kadanes_Algorithm)
pair<ll,ll>Kadanes_Algorithm(vector<ll>arr) {
    ll mx = arr[0],mn=arr[0];
    ll mxend = arr[0],mnend=arr[0];

    for (int i = 1; i < arr.size(); i++) {
        mxend = max(mxend + arr[i], arr[i]);
        mx = max(mx, mxend);

        mnend = min(mnend + arr[i], arr[i]);
        mn = min(mn, mnend);
    }
    return {mx,mn};
}

//=========================================================================
(ordered multiset)           		complex 4*log
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_multiset <ll> os;

os.order_of_key (k)  // Number of items strictly smaller than k
*os.find_by_order(k) // K-th element in a set (counting from zero)

//=========================================================================
(ordered set)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ordered_set os;

//=========================================================================
(SingleHashing)
ll fp(ll x, ll k,ll mod){
	ll ret = 1;
	x%=mod;
	while (k){
		if (k & 1) ret = (ret%mod*x) % mod;
		k >>= 1; x = (x*x) % mod;
	}
	return ret%mod;
}
ll fix(ll x,ll mod){return (x%mod+mod)%mod;}

const int N=1e6+5,mod=1e9+7,base=31;
ll pw[N];

void pre(){
    pw[0]=1;

    for(int i=1;i<N;i++){
        pw[i]=fix(base*pw[i-1],mod);
    }
}

struct SingleHashing{
    ll len,h,ha1,inv;
    vector<ll>pref,suf;

    SingleHashing(){
        len=h=0,
        inv=fp(base,mod-2,mod);
    }

    SingleHashing(string s){
        ha1=0;
        pref=suf=vector<ll>(s.size()+2);

        for(int i=1;i<s.size();i++){
            int ch=s[i]-'a'+1;

            ha1=fix(ha1*base+ch,mod),
            pref[i]=ha1;
        }

        ha1=0;
        for(int i=s.size()-1;i;i--){
            int ch=s[i]-'a'+1;

            ha1=fix(ha1*base+ch,mod),
            suf[i]=ha1;
        }
    }

    void push_b(char c){
        int ch=c-'a'+1;

        h=fix(h*base+ch,mod),
        len++;
    }

    void pop_b(char c){
        if(!len)return;

        int ch=c-'a'+1;

        h=fix(h-ch,mod);
        len--;
    }

    void push_f(char c){
        int ch=c-'a'+1;

        h=fix(h+pw[len]*ch,mod),
        len++;
    }

    void pop_f(char c){
        if(!len)return;

        int ch=c-'a'+1;

        h=fix(h-ch*pw[len-1],mod),
        len--;
    }

    ll get(){
        return h;
    }

    ll GetPre(int l,int r){
        ll ret=pref[r];

        ret=fix(ret-pref[l-1]*pw[r-l+1],mod);
        return ret;
    }

    ll GetSuf(int l,int r){
        ll ret=suf[l];

        ret=fix(ret-suf[r+1]*pw[r-l+1],mod);
        return ret;
    }
};

//=========================================================================
(DoubleHashing)
ll fp(ll x, ll k,ll mod){
	ll ret = 1;
	x%=mod;
	while (k){
		if (k & 1) ret = (ret%mod*x) % mod;
		k >>= 1; x = (x*x) % mod;
	}
	return ret%mod;
}
ll fix(ll x,ll mod){return (x%mod+mod)%mod;}
 
const int N=1e6+5,mod=1e9+7,mod2=2e9+11,base=31,base2=37;
ll pw[N],pw2[N];
 
void pre(){
    pw[0]=pw2[0]=1;
 
    for(int i=1;i<N;i++){
        pw[i]=fix(base*pw[i-1],mod),
        pw2[i]=fix(base2*pw2[i-1],mod2);
    }
}
 
struct DoubleHashing{
    ll len,h,h2,ha1,ha2,inv,inv2;
    vector<pair<ll,ll>>pref,suf;
 
    DoubleHashing(){
        len=h=h2=0,
        inv=fp(base,mod-2,mod),inv2=fp(base2,mod2-2,mod2);
    }
 
    DoubleHashing(string s){
        ha1=ha2=0;
        pref=suf=vector<pair<ll,ll>>(s.size()+2);
 
        for(int i=1;i<s.size();i++){
            int ch=s[i]-'a'+1;
 
            ha1=fix(ha1*base+ch,mod),
            ha2=fix(ha2*base2+ch,mod2),
            pref[i]={ha1,ha2};
        }
 
        ha1=ha2=0;
        for(int i=s.size()-1;i;i--){
            int ch=s[i]-'a'+1;
 
            ha1=fix(ha1*base+ch,mod),
            ha2=fix(ha2*base2+ch,mod2),
            suf[i]={ha1,ha2};
        }
    }
 
    void push_b(char c){
        int ch=c-'a'+1;
 
        h=fix(h*base+ch,mod),
        h2=fix(h2*base2+ch,mod2),
 
        len++;
    }
 
    void pop_b(char c){
        if(!len)return;
 
        int ch=c-'a'+1;
 
        h=fix(h-ch,mod),
        h=fix(h*inv,mod),
 
        h2=fix(h2-ch,mod2),
        h2=fix(h2*inv2,mod2),
 
        len--;
    }
 
    void push_f(char c){
        int ch=c-'a'+1;
 
        h=fix(h+pw[len]*ch,mod),
        h2=fix(h2+pw2[len]*ch,mod2),
 
        len++;
    }
 
    void pop_f(char c){
        if(!len)return;
 
        int ch=c-'a'+1;
 
        h=fix(h-ch*pw[len-1],mod),
        h2=fix(h2-ch*pw2[len-1],mod2),
 
        len--;
    }
 
    pair<ll,ll>get(){
        return {h,h2};
    }
 
    pair<ll,ll>GetPre(int l,int r){
        pair<ll,ll>ret=pref[r];
 
        ret.first=fix(ret.first-pref[l-1].first*pw[r-l+1],mod);
        ret.second=fix(ret.second-pref[l-1].second*pw2[r-l+1],mod2);
 
        return ret;
    }
 
    pair<ll,ll>GetSuf(int l,int r){
        pair<ll,ll>ret=suf[l];
 
        ret.first=fix(ret.first-suf[r+1].first*pw[r-l+1],mod);
        ret.second=fix(ret.second-suf[r+1].second*pw2[r-l+1],mod2);
 
        return ret;
    }
};

//=========================================================================
(KMP)
struct KMP{
    vector<int>PreFun(string pat){
        vector<int>v(pat.size());

        int k=0;
        for(int i=1;i<pat.size();i++){

            while(k&&pat[k]!=pat[i])k=v[k-1];
            if(pat[k]==pat[i])k++;

            v[i]=k;
        }

        return v;
    }

    int kmp(string s,string pat){
        vector<int>v=PreFun(pat);

        int k=0,ans=0;
        for(int i=0;i<s.size();i++){

            while(k&&pat[k]!=s[i])k=v[k-1];
            if(pat[k]==s[i])k++;

            if(k==pat.size())ans++,k=0; //k=v[k-1]
        }

        return ans;
    }

    vector<vector<int>>Compute(string s){
        vector<int>v=PreFun(s);
        vector<vector<int>>ret(s.size(),vector<int>(26));

        for(int i=0;i<s.size();i++){
            for(int c=0;c<26;c++){
                int k=i;

                while(k&&s[k]-'a'!=c)k=v[k-1];
                if(s[k]-'a'==c)k++;

                ret[i][c]=k;
            }
        }

        return ret;
    }
};

//=========================================================================
(Trie)
struct Trie{

    Trie*ch[26];
    int pre;

    Trie(){
        pre=0,
        memset(ch,0,sizeof ch);
    }

    void in(string s){
        auto*cur=this;

        for(auto i:s){
            int id=i-'a';

            if(cur->ch[id]==0)
                cur->ch[id]=new Trie();

            cur=cur->ch[id],
            cur->pre++;
        }
    }

    int cnt(string s){

        auto*cur=this;
    }
};

//=========================================================================
(MOs)
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
int n,q,x[N],vis[(ll)1e6+6],ret;
ll ans[N];

void add(int id){

    ret-=vis[x[id]]==x[id];
    vis[x[id]]++;
    ret+=vis[x[id]]==x[id];
}

void del(int id){

    ret-=vis[x[id]]==x[id];
    vis[x[id]]--;
    ret+=vis[x[id]]==x[id];
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
	
    while(l<=r)del(l++);
}

for(int i=0;i<q;i++){
    int l,r;cin>>l>>r;
 
    qu[i]=query(--l,--r,i);
}

//=========================================================================
(MOs,Tree)
const int sqr=500,N=2e5+5;
vector<int>adj[N],v;

struct query{
    int l,r,idblk,idq,lca;

    query(){}

    query(int _l,int _r,int _idq,int lc){
        l=_l,r=_r,idq=_idq,idblk=l/sqr,lca=lc;
    }

    bool operator<(const query&q)const{
        if(idblk!=q.idblk)return idblk<q.idblk;

        return r<q.r;
    }
};

query qu[N];
int n,q,x[N],vis[(ll)1e6+6],cnt[(ll)1e6+6];
ll ans[N],ret;

void pross(int node){		// use add and del if it must!!
    if(!vis[node]&&++cnt[x[node]]==1)ret++;
    if(vis[node]&&--cnt[x[node]]==0)ret--;

    vis[node]^=1;
}

int timer,in[N],out[N];
void MOsTree(){
    sort(qu,qu+q);

    int l=1,r=0;

    for(int i=0;i<q;i++){
        int a=v[qu[i].l],b=v[qu[i].r];

        while(l<qu[i].l)pross(v[l++]);
        while(l>qu[i].l)pross(v[--l]);

        while(r<qu[i].r)pross(v[++r]);
        while(r>qu[i].r)pross(v[r--]);

        int lca=qu[i].lca;

        if(lca!=a&&lca!=b)pross(lca);

        ans[qu[i].idq]=ret;

        if(lca!=a&&lca!=b)pross(lca);
    }

    for(int i=0;i<q;i++)
        cout<<ans[i]<<'\n';

    while(l<=r)del(l++);
}

void dfs(int node=1,int par=-1){
    in[node]=timer++;
    v.push_back(node);

    for(auto i:adj[node])
        if(i!=par)dfs(i,node);

    out[node]=timer++,
    v.push_back(node);
}

for(int i=0;i<q;i++){
    int l,r,lca;cin>>l>>r,lca=lc.LCA(l,r);
 
    if(in[l]>in[r])swap(l,r);
 
    if(lca!=l)
        qu[i]=query(out[l],in[r],i,lca);
    else
        qu[i]=query(in[l],in[r],i,lca);
}

//=========================================================================
(DSU)
struct DSU{
    vector<ll>par,sz;
    ll sm,components;
 
    DSU(ll n){
        sm=0,components=n;
        par=sz=vector<ll>(n+1);
        for(int i=0;i<=n;i++)par[i]=i,sz[i]=1;
    }
 
    ll findlead(ll n){
        if(par[n]==n)return n;
        return par[n]=findlead(par[n]);
    }
 
    bool merge(ll x,ll y,ll c){
        x=findlead(x),y=findlead(y);
        if(x==y)return 0;
 
        sm+=c,components--;
        if(sz[x]>=sz[y])sz[x]+=sz[y],par[y]=x;
        else sz[y]+=sz[x],par[x]=y;
        return 1;
}
};

//=========================================================================
(HLD)
const int N=1e4+5;
vector<pair<int,int>>adj[N];
vector<int>x;
 
struct HLD{
    vector<int>heavy,head,par,id,dep,sz,val;
    int nxt;
 
    HLD(int n):heavy(n+1),head(n+1),id(n+1),par(n+1),dep(n+1),val(n+1),sz(n+1,1){
        Dfs();
        nxt=1;
        head[1]=1;
        Flatten();
    }
 
    void Dfs(int node=1){
        for(auto [a,b]:adj[node]){
            if(a==par[node])continue;
 
            par[a]=node;
            dep[a]=dep[node]+1;
            val[a]=b;
            Dfs(a);
            sz[node]+=sz[a];
 
            if(!heavy[node]||sz[a]>sz[heavy[node]])heavy[node]=a;
        }
    }
 
    void Flatten(int node=1){
        id[node]=nxt++;
 
        if(heavy[node])
            head[heavy[node]]=head[node],
            Flatten(heavy[node]);
 
        for(auto [a,b]:adj[node]){
            if(a==par[node]||a==heavy[node])continue;
 
            head[a]=a;
            Flatten(a);
        }
    }
 
    vector<pair<int,int>>Path(int u,int v){
        vector<pair<int,int>>ret;
 
        while(1){
            if(head[u]==head[v]){
                if(dep[u]>dep[v])swap(u,v);
 
                ret.push_back({id[u]+1,id[v]});
                return ret;
            }
 
            if(dep[head[u]]>dep[head[v]])swap(u,v);
            ret.push_back({id[head[v]],id[v]});
            v=par[head[v]];
        }
    }
 
};

//=========================================================================
(Centroid_Decomposition)

const int N=2e5+5;
vector<int>adj[N];
struct Centroid_Decomposition{

    vector<int>Sz,Is_Removed;
    vector<vector<pair<int, int>>> Centroids;

    Centroid_Decomposition(int n){
        Sz=Is_Removed=vector<int>(n+1);
        Centroids=vector<vector<pair<int,int>>>(n+1);
        Build_Centroid();
    }

    int Get_SubTreeSz(int node, int par = -1) {
        Sz[node] = 1;
        for (int i : adj[node]) {
            if(i == par || Is_Removed[i])continue;

            Sz[node] += Get_SubTreeSz(i, node);
        }

        return Sz[node];
    }

    int Get_Centroid(int node, int TreeSize, int par = -1) {
        for (int i : adj[node]) {
            if(i == par || Is_Removed[i])continue;

            if(Sz[i] * 2 > TreeSize)
                return Get_Centroid(i, TreeSize, node);
        }

        return node;
    }

    void Get_Dis(int node, int centroid, int par = -1, int dis = 1) {
        for (int i : adj[node]) {
            if(i == par || Is_Removed[i])continue;

            dis++,
            Get_Dis(i, centroid, node, dis),
            dis--;
        }

        Centroids[node].push_back({centroid, dis});
    }

    void Build_Centroid(int node = 1) {
        int centroid = Get_Centroid(node, Get_SubTreeSz(node));

        for (int i : adj[centroid]) {
            if(Is_Removed[i])continue;

            Get_Dis(i, centroid, centroid);
        }

        Is_Removed[centroid] = 1;
        for (int i : adj[centroid]) {
            if(Is_Removed[i])continue;

            Build_Centroid(i);
        }
    }
};

//=========================================================================
(DSU on Trees (Sack))
const int N=5e5+5;
vector<int>adj[N];
int big[N],sz[N],fre[N][26],dep[N],ans[N];
string s;

void pre(int node,int par){
    sz[node]=1;
    for(auto i:adj[node]){
        if(i==par)continue;

        pre(i,node);

        sz[node]+=sz[i];

        if(!big[node]||sz[i]>sz[big[node]])
            big[node]=i;
    }
}

void up(int node,int add){
   // change here
}

void collect(int node,int par,int add){
    up(node,add);

    for(auto i:adj[node])
        if(i!=par)collect(i,node,add);
}

vector<pair<int,int>>v[N];
void dfs(int node,int par,int ok){
    for(auto i:adj[node])
        if(i!=par&&big[node]!=i)
            dfs(i,node,0);

    if(big[node])
        dfs(big[node],node,1);

    up(node,1);

    for(auto i:adj[node])
        if(i!=par&&i!=big[node])
            collect(i,node,1);

    // answer queries here

    if(!ok)
        collect(node,par,-1);
}

//=========================================================================
(SCC)
void SCC(ll node){
    dn[node] = low[node] = id++;
    st.push(node);
    in[node] = 1,vis[node]=1;

    for(auto&i:adj[node]){
        if(i == node)continue;
        if(!dn[i]){
            SCC(i);
            low[node] = min(low[node],low[i]);
        }else if(in[i]){
            low[node] = min(low[node],dn[i]);
        }
    }
    if(dn[node] == low[node]){
        ll x = -1;
        comp.push_back({});

        while(x!=node){
            x = st.top();
            st.pop();
            in[x] = 0;
            comp.back().push_back(x);
        }
    }
}

//=========================================================================
(Bridges)
void bridges(ll node,ll par){
    vis[node]=1;
    low[node]=dn[node]=id++;

    for(auto i:adj[node]){
        if(par==i)continue;

        if(!vis[i]){
            bridges(i,node);
            low[node]=min(low[node],low[i]);
            if(low[i]>dn[node])s.insert({node,i});
        }
        else low[node]=min(low[node],dn[i]);
    }
}

//=========================================================================
(Articulation_Points)
void articulation_points(ll node,ll par){
    vis[node]=1;
    low[node]=dn[node]=id++;
    int c=0;

    for(auto i:adj[node]){
        if(par==i)continue;

        if(!vis[i]){
            articulation_points(i,node);
            low[node]=min(low[node],low[i]);
            if(low[i]>=dn[node]&&~par)arc.insert(node);
        c++;
        }
        else low[node]=min(low[node],dn[i]);
    }

    if(par==-1&&c>1)arc.insert(node);
}

//=========================================================================
(LCA)
struct st{
    ll par;
};
 
struct Lowest_CA{
    int lg;
    vector<vector<st>>anc;
    vector<int>lvl;
 
    Lowest_CA(int n){
        lg=27,
        anc=vector<vector<st>>(n+1,vector<st>(lg)),
        lvl=vector<int>(n+1);
 
        bul();
    }
 
    void bul(int node=1,int par=1){
        lvl[node]=lvl[par]+1;
 
        anc[node][0].par=par;
        for(int i=1;i<lg;i++){
            int p=anc[node][i-1].par;
            anc[node][i].par=anc[p][i-1].par;
        }
 
        for(auto i:adj[node]){
            if(i!=par)
                bul(i,node);
        }
    }
 
    int kth(int node,int k){
        for(int i=lg-1;i>=0;i--)
            if(k>>i&1)node=anc[node][i].par;
 
        return node;
    }
 
    int LCA(int u,int v){
        if(lvl[u]<lvl[v])swap(u,v);
        u=kth(u,lvl[u]-lvl[v]);
 
        if(u==v)return u;
        for(int i=lg-1;i>=0;i--){
            if(anc[u][i].par!=anc[v][i].par)
                u=anc[u][i].par,v=anc[v][i].par;
        }
 
        return anc[u][0].par;
    }
 
    int distance(int u,int v){
        return lvl[u]+lvl[v]-lvl[LCA(u,v)]*2;
    }
};
//=========================================================================
vector<int> genAllSubmask(int mask) {
	vector<int> v;
	for (int subMask = mask;; subMask = (subMask - 1) & mask) {
		v.push_back(subMask);
		if (subMask == 0)
			break;
	}
	return v;
}


ll setBit(ll num, int idx, bool val) {
	return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}
 
ll flipBit(ll num, int idx) {
	return (num ^ (1LL << idx));
}

int getbit(int n,int j){
	return((n>>j)&1);
}

__builtin_popcount(n);

//=========================================================================
(LIS and number of LISes)
ll n,mod=1e9+7;cin>>n;
vector<ll>x(n),dp(n,1),dp2(n,1);
for(auto&i:x)cin>>i;
 
for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
    if(x[i]<=x[j])continue;
 
    if(dp[j]+1>dp[i]){
        dp[i]=dp[j]+1;
        dp2[i]=dp2[j]%mod;
    }
    else if(dp[j]+1==dp[i])
        dp2[i]=(dp2[i]+dp2[j])%mod;
}}
ll mx=*max_element(all(dp)),ans=0;
 
for(int i=0;i<n;i++)
    if(dp[i]==mx)ans=(ans+dp2[i])%mod;
 
cout<<mx<<' '<<ans<<'\n';

//=========================================================================
(Sum of 2 strings)
// C++ program to find sum of two large numbers.
#include<bits/stdc++.h>
using namespace std;

// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
	// Before proceeding further, make sure length
	// of str2 is larger.
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate length of both string
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i=0; i<n1; i++)
	{
		// Do school mathematics, compute sum of
		// current digits and carry
		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');

		// Calculate carry for next step
		carry = sum/10;
	}

	// Add remaining digits of larger number
	for (int i=n1; i<n2; i++)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	// Add remaining carry
	if (carry)
		str.push_back(carry+'0');

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}

//=========================================================================
(multi 2 strings)
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}
	
//=========================================================================
(subtract 2 strings)
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) {
        // Do school mathematics, compute difference of
        // current digits

        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);

        // If subtraction is less than zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

//=========================================================================
(divide string , num ){
string divideLargeNumber(string number, int divisor) {
   // to store the result
   string result;
   int index = 0;
   // extracting the part that is greater than the given divisor
   int dividend = number[index] - '0';
   while (dividend < divisor) {
      dividend = dividend * 10 + (number[++index] - '0');
   }
   // iterating until all digits participate in the division
   while (number.size() > index) {
      result += (dividend / divisor) + '0';
      // adding the next digit to the dividend
      dividend = (dividend % divisor) * 10 + number[++index] - '0';
   }
   if (result.length() == 0) {
      return "0";
   }
   return result;
}
}
//=========================================================================
(calc max path for each vertex)
const int N=2e5+5;
vector<int>adj[N],MxPath;
int mx,o;
void dfs(int node,int par,int d){
    MxPath[node]=max(MxPath[node],d);

    if(d>mx)
        mx=d,o=node;

    for(auto i:adj[node])
        if(i!=par)dfs(i,node,d+1);
}

dfs(1,0,0);
mx=0;
dfs(o,0,0);
dfs(o,0,0);

}
//=========================================================================
ll XorRange(ll l,ll r){
    l--;
    ll mod1 = l%4,mod2 = r%4;
    
    if(!mod1)l = l;
    else if(mod1 == 1)l = 1;
    else if(mod1 == 2)l = l+1;
    else l=0;

    if(!mod2)r = r;
    else if(mod2 == 1)r = 1;
    else if(mod2 == 2)r = r+1;
    else r = 0;

    return l ^ r;
}
//=========================================================================
// Segment_Tree
(Max Subseq Brackets with segment tree)
st merge(st x,st y){
    st ret;

    int mn=min(x.l,y.r);
    ret.ans=x.ans+y.ans+mn;
    ret.l=x.l+y.l-mn;
    ret.r=x.r+y.r-mn;

    return ret;
}

(Max Subsarray with segment tree)
void merge(int node){
    seg[node].ans=max({seg[node*2].ans,seg[node*2+1].ans,seg[node*2].suf+seg[node*2+1].pre});
    seg[node].pre=max(seg[node*2].pre,seg[node*2].sm+seg[node*2+1].pre);
    seg[node].suf=max(seg[node*2+1].suf,seg[node*2+1].sm+seg[node*2].suf);
    seg[node].sm=seg[node*2].sm+seg[node*2+1].sm;
}
//=========================================================================
========
=******=
=*####*=
=*#++#*=	(traverse this shape from out to in this shape)
=*####*=
=******=
========

for(int k=0;k<min(n/2,m/2);k++){
    for(int j=k;j<m-k;j++)
        //

    for(int i=k+1;i<n-k;i++)
        //

    for(int j=m-2-k;j>=k;j--)
        //

    for(int i=n-2-k;i>k;i--)
        //
}

//====================================================
(for mark every dash from number 0 to 9 in this shape)    
 ____
 |  |
 |--|		// its 8 with dash
 |  |
 ____
vector<vector<int>>dig(10,vector<int>(7));
dig[0][0]=dig[0][1]=dig[0][2]=dig[0][3]=dig[0][4]=dig[0][5]=1;
dig[1][1]=dig[1][2]=1;
dig[2][0]=dig[2][1]=dig[2][3]=dig[2][4]=dig[2][6]=1;
dig[3][0]=dig[3][1]=dig[3][2]=dig[3][3]=dig[3][6]=1;
dig[4][1]=dig[4][2]=dig[4][5]=dig[4][6]=1;
dig[5][0]=dig[5][2]=dig[5][3]=dig[5][5]=dig[5][6]=1;
dig[6][0]=dig[6][2]=dig[6][3]=dig[6][4]=dig[6][5]=dig[6][6]=1;
dig[7][0]=dig[7][1]=dig[7][2]=1;
dig[8][0]=dig[8][1]=dig[8][2]=dig[8][3]=dig[8][4]=dig[8][5]=dig[8][6]=1;
dig[9][0]=dig[9][1]=dig[9][2]=dig[9][3]=dig[9][5]=dig[9][6]=1;
