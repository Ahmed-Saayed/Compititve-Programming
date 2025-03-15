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
            int ch=s[i]-'0'+1;

            ha1=fix(ha1*base+ch,mod),
            ha2=fix(ha2*base2+ch,mod2),
            pref[i]={ha1,ha2};
        }

        ha1=ha2=0;
        for(int i=s.size()-1;i;i--){
            int ch=s[i]-'0'+1;

            ha1=fix(ha1*base+ch,mod),
            ha2=fix(ha2*base2+ch,mod2),
            suf[i]={ha1,ha2};
        }
    }

    void push_b(char c){
        int ch=c-'0'+1;

        h=fix(h*base+ch,mod),
        h2=fix(h2*base2+ch,mod2),

        len++;
    }

    void pop_b(char c){
        if(!len)return;

        int ch=c-'0'+1;

        h=fix(h-ch,mod),
        h=fix(h*inv,mod),

        h2=fix(h2-ch,mod2),
        h2=fix(h2*inv2,mod2),

        len--;
    }

    void push_f(char c){
        int ch=c-'0'+1;

        h=fix(h+pw[len]*ch,mod),
        h2=fix(h2+pw2[len]*ch,mod2),

        len++;
    }

    void pop_f(char c){
        if(!len)return;

        int ch=c-'0'+1;

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

int main()
{
Ahmed_Sayed();
pre();

tt
int n,k;
string s,s1,s2;
cin>>n>>k>>s,s='*'+s;

int c=0;
while(s1.size()<n){
   for(int i=0;i<k;i++)
        s1+=(c?'0':'1');

    c=!c;
}

c=0;
while(s2.size()<n){
   for(int i=0;i<k;i++)
        s2+=(!c?'0':'1');

    c=!c;
}

s1='*'+s1,s2='*'+s2;
DoubleHashing op1(s1),op2(s2),op3(s);

int ans=-1;
for(int i=1;i<n;i++){
    if((op3.GetSuf(1,i)==op1.GetPre(n-i+1,n)&&op3.GetPre(i+1,n)==op1.GetPre(1,n-i))
       ||(op3.GetSuf(1,i)==op2.GetPre(n-i+1,n)&&op3.GetPre(i+1,n)==op2.GetPre(1,n-i)))
        ans=i;
}

cout<<ans<<'\n';}
}
