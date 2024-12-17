class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++)mp[arr[i]].push_back(i);

        vector<bool>vis(n);
        queue<pair<int,int>>q;
        q.push({0,0});
        while(q.size()){
            auto[cost,node]=q.front();q.pop();

            if(node==n-1)return cost;

            if(node-1>=0&&!vis[node-1])
                vis[node-1]=1,q.push({cost+1,node-1});

            if(node+1<n&&!vis[node+1])
                vis[node+1]=1,q.push({cost+1,node+1});

            for(auto i:mp[arr[node]])
                if(!vis[i])vis[i]=1,q.push({cost+1,i});

            mp[arr[node]].clear();
        }

        return -1;
    }
};