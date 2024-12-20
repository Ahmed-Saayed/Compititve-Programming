class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<>>pq;
        vector<int>x=arr;
        
        sort(x.begin(),x.end());
        
        int i=0,ans=0;
        for(auto j:arr){
            pq.push(j);

            while(pq.size()&&x[i]==pq.top())
                i++,pq.pop();

            if(pq.empty())
                ans++;
        }

        return ans;
    }
};