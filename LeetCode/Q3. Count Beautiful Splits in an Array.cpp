#define ll long long

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

const int N=6e3,mod=1e9+7,base=61;
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

};©leetcode