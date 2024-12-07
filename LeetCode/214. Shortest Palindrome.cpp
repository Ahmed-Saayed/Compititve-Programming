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

const int N=5e4+5,mod=1e9+7,base=31;
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
class Solution {
public:

    
    string shortestPalindrome(string s) {
        pre();
        int i=0,j=s.size()-1,pala=1;
        while(i<j && pala)
            if(s[i++]!=s[j--])pala=0;

        if(pala)return s;

            s='*'+s;
            SingleHashing op(s);

            int id=-1;
            for(int i=s.size()-1;i>1;i--)
                if(op.GetPre(1,i/2)==op.GetSuf(i/2+1+i%2,i)){
                    id=i;break;
                }


            if(id==-1){
                string t=s.substr(2,s.size());
                reverse(t.begin(),t.end());

                return t+s.substr(1,s.size());
            }

            else{
                string t=s.substr(id+1,s.size());

                reverse(t.begin(),t.end());
                return t+string(s.begin()+1,s.end());
            }

    }
};