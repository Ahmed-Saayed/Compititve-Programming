class Solution {
public:
    string getPermutation(int n, int k) {
        int c=0;
        vector<int>v;
        for(int i=1;i<=n;i++)v.push_back(i);

        string ret;
        do{
            c++;
            if(c==k){
                for(auto i:v)ret+=i+'0';
                return ret;
            }
        }while(next_permutation(v.begin(),v.end()));

        return ret;
    }
};