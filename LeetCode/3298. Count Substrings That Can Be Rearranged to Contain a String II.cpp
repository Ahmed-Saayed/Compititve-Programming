class Solution {
public:
    long long validSubstringCount(string s, string t) {
        long long n=s.size(),ans=0;
        
        vector<long long>fre1(26),fre2(26);
        set<char>st;
        for(auto i:t)
            st.insert(i),fre2[i-'a']++;

        int c=0,o=0;
        for(int i=0;i<n;i++){
            fre1[s[i]-'a']++;

            if(fre1[s[i]-'a']==fre2[s[i]-'a'])c++;

            while(c==st.size()){
                ans+=n-i;
                
                if(fre1[s[o]-'a']--==fre2[s[o]-'a'])c--;
                o++;
            }
        }

        return ans;
    }
};