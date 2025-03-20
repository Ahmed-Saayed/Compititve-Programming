class Solution {
public:
    bool is_dig(char c){
        return c>='0'&&c<='9';
    }
    bool is_char(char c){
        return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
    }

    bool isNumber(string s) {
        int p=0,c=0,v=0;
#define ll long long

struct DSU{
    vector<ll>par,sz,val;
    ll sm,components;

    DSU(ll n){
        sm=0,components=n;
        par=sz=val=vector<ll>(n+1);
        for(int i=0;i<=n;i++)
            par[i]=i,sz[i]=1,val[i]=(1ll<<28)-1;
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

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU op(n);
        for(auto i:edges)
            op.merge(i[0],i[1],0);

        for(auto i:edges)
            op.val[op.findlead(i[0])]&=i[2];

        vector<int>ans;
        for(auto i:query)
            ans.push_back(op.findlead(i[0])==op.findlead(i[1])?op.val[op.findlead(i[0])]:-1);

        return ans;
    }
};
        for(int i=0;i<s.size();i++){
            if(s[i]=='E'||s[i]=='e'){
                p=1,c++;
                if(!(i+1!=s.size()&&i))return 0;
            }

            if(s[i]=='.'){
                v++;
                if(p||(!i||!is_dig(s[i-1]))&&(i+1==s.size()||!is_dig(s[i+1])))return 0;
            }

            if(s[i]=='+'||s[i]=='-'){
                if(!(!i||s[i-1]=='E'||s[i-1]=='e')||i+1==s.size()||(!is_dig(s[i+1])&&s[i+1]!='.'))return 0;
                
            }

            if(s[i]!='E'&&s[i]!='e'&&is_char(s[i]))return 0;
        }

        return (c<2&&v<2);
    }
};