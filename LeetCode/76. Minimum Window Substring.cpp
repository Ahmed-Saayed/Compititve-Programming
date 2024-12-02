class Solution {
public:

    string minWindow(string s, string t) {
        map<char,int>fre,fre2;   
        for(auto i:t)fre2[i]++;

        string ans="";

        int l=1,r=s.size();
        while(l<=r){
            int m=l+r>>1,o=0,p=0;
            fre.clear();

            for(int i=0;i<s.size();i++){
                fre[s[i]]++;

                if(i-o+1==m){
                    p=1;
                    for(auto[a,b]:fre2)
                        if(fre[a]<b){p=0;break;}

                    if(p){
                        ans=string(s.begin()+o,s.begin()+i+1);
                        break;
                    }
                    fre[s[o++]]--;
                }
            }

            (!p?l=m+1:r=m-1);
        }

        return ans;
    }
};