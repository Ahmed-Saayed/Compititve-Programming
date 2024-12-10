class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int ans=0,id=0,c=0;
        while(n1--){
            for(auto i:s1){
                if(i==s2[id])id++;

                if(id==s2.size())c++,id=0;

                if(c==n2)ans++,c=0;
            }
        }

        return ans;
    }
};