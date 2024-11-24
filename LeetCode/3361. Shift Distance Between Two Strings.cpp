#define ll long long
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& next, vector<int>& pre) {
        ll ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                char c=s[i];
                ll cost1=0,cost2=0;

                while(c!=t[i]){
                    cost1+=pre[c-'a'];

                    (c=='a'?c='z':c--);
                }

                c=s[i];

                while(c!=t[i]){
                    cost2+=next[c-'a'];

                    (c=='z'?c='a':c++);
                }
                ans+=min(cost1,cost2);
            }
        }

        return ans;
    }
};