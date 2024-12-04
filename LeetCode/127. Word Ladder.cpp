bool ok(string s, string t){
        int ret=0;
        for(int i=0;i<s.size();i++)
            if(s[i]!=t[i])ret++;

        return ret==1;
    }

class Solution {
    public:
    int ladderLength(string s, string t, vector<string>& v) {
        int n=v.size();
        vector<bool>vis(n);

        queue<pair<int,string>>q;
        q.push({0,s});
        while(q.size()){
            auto[cost,node]=q.front();q.pop();

            if(node==t)return cost+1;

            for(int i=0;i<n;i++){
                if(!vis[i]&&ok(node,v[i]))
                    vis[i]=1,q.push({cost+1,v[i]});
            }
        }
        
        return 0;
    }
};