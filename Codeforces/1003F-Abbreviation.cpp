#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
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

vector<ll>MyPref(vector<pair<ll,ll>>pat){
    vector<ll>v(pat.size());

    int k=0;
    for(int i=1;i<pat.size();i++){

        while(k&&pat[k]!=pat[i])k=v[k-1];
        if(pat[k]==pat[i])k++;

        v[i]=k;
    }

    return v;
}

int KMP(vector<pair<ll,ll>>s,vector<pair<ll,ll>>pat){
    vector<ll>v=MyPref(pat);

    int k=0,cnt=0;
    for(int i=0;i<s.size();i++){

        while(k&&pat[k]!=s[i])k=v[k-1];
        if(pat[k]==s[i])k++;

        if(k==pat.size()){
            k=0;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
Ahmed_Sayed();
pre();

ll n,sz=0,ans=1e9;cin>>n;
ll pref[n];
vector<pair<ll,ll>>x(n);

for(int i=0;i<n;i++){
    string o;cin>>o;
    sz+=o.size();
    pref[i]=o.size()+(i?pref[i-1]:0);

    DoubleHashing h;
    for(auto j:o)h.push_b(j);
    x[i]=h.get();
}

ans=sz+n-1;
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){

        ll check=KMP(x,vector<pair<ll,ll>>{x.begin()+i,x.begin()+j+1});

        if(check-1){
            ll u=sz+n-1-(pref[j]-(i?pref[i-1]:0))*check-(j-i)*check+(j-i+1)*check;
            ans=min(ans,u);
        }
    }
}

cout<<ans;
}