class Solution {
public:

    int maxRemoval(vector<int>& x, vector<vector<int>>& q) {
        int n=x.size();

        sort(q.begin(),q.end());
       
        vector<vector<int>>adj(n);
        for(auto i:q)adj[i[0]].push_back(i[1]);

        priority_queue<int>pq;

        int c=0;
        vector<int>pre(n+1);
        for(int i=0;i<n;i++){
            for(auto j:adj[i])pq.push(j);

            c+=pre[i],
            x[i]-=c;

            while(x[i]>0){
                if(!pq.size()||pq.top()<i)return -1;

                c++,
                pre[pq.top()+1]--,
                pq.pop();
                x[i]--;
            }
        }
       
        return pq.size();
    }
};