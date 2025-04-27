#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
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

            if(k==pat.size())ans++,k=v[k-1];
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

int main()
{
Ahmed_Sayed();
string a,b;cin>>a>>b;

KMP op;
cout<<op.kmp(a,b);
}
