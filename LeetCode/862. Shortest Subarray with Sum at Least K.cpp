class Solution {
public:
    int shortestSubarray(vector<int>& v, int k) {
        vector<long long>x;
        for(auto i:v)x.push_back(i);
        
        int ans=1e9;
        deque<int>d;

        for(int i=0;i<x.size();i++){
            if(i)x[i]+=x[i-1];

            if(x[i]>=k)
                ans=min(ans,i+1);

            while(d.size()&&x[i]-x[d.front()]>=k)
                ans=min(ans,i-d.front()),d.pop_front();

            while(d.size()&&x[i]<x[d.back()])d.pop_back();

            d.push_back(i);
        }

        return ans==1e9?-1:ans;
    }
};