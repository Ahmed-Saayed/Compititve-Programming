class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int>vis(n),mx(n,1);

        for(auto i:favorite)
            vis[i]++;

        queue<int>q;
        for(int i=0;i<n;i++)
            if(!vis[i])q.push(i);

        while(q.size()){
            int node=q.front(),nxt=favorite[node];q.pop();

            mx[nxt]=max(mx[nxt],mx[node]+1);

            if(--vis[nxt]==0)
                q.push(nxt);
        }

        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            if(!vis[i])continue;

            int node=i,c=0;
            while(vis[node]){
                c++,
                vis[node]=0,

                node=favorite[node];
            }

            if(c==2)
                ans2+=mx[node]+mx[favorite[node]];
            else
                ans1=max(ans1,c);
        }

        return max(ans1,ans2);
    }
};