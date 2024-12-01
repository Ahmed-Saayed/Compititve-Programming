#define ll long long

struct st{
    ll par;
    //,mx,mn,sm;
};

struct Lowest_CA{
    int lg;
    vector<vector<st>>anc;
    vector<vector<int>>adj;
    vector<int>lvl;

    Lowest_CA(int n,vector<vector<int>>v){
        lg=27,adj=v,
        anc=vector<vector<st>>(n+1,vector<st>(lg)),
        lvl=vector<int>(n+1);
    }

    void bul(int node=1,int par=1){
        lvl[node]=lvl[par]+1;

        anc[node][0].par=par;
        for(int i=1;i<lg;i++){
            int p=anc[node][i-1].par;
            anc[node][i].par=anc[p][i-1].par;
            //anc[node][i].sm=anc[node][i-1].sm+anc[p][i-1].sm;
        }

        for(auto i:adj[node]){
            if(i!=par)
                bul(i,node);
        }
    }

    int kth(int node,int k){
        for(int i=lg-1;i>=0;i--)
            //ans=max(ans,anc[node][i].mx),
            //sm=max(ans,anc[node][i].sm),
            if(k>>i&1)node=anc[node][i].par;

        return node;
    }

    int LCA(int u,int v){
        if(lvl[u]<lvl[v])swap(u,v);
        u=kth(u,lvl[u]-lvl[v]);

        if(u==v)return u;
        for(int i=lg-1;i>=0;i--){
            if(anc[u][i].par!=anc[v][i].par)
                u=anc[u][i].par,v=anc[v][i].par;
        }

        return anc[u][0].par;
    }

    int distance(int u,int v){
        return lvl[u]+lvl[v]-lvl[LCA(u,v)]*2;
    }
};


class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>adj(n+1),adj2(m+1);
        
      
        for(auto i:edges1)
            adj[i[0]+1].push_back(i[1]+1),
            adj[i[1]+1].push_back(i[0]+1);
    
        for(auto i:edges2)
            adj2[i[0]+1].push_back(i[1]+1),
            adj2[i[1]+1].push_back(i[0]+1);


        Lowest_CA op1(n,adj),op2(m,adj2);
        op1.bul(),op2.bul();
        
         int mx=0;
         for(int i=1;i<=m;i++){
            int c=0;
        
            for(int j=1;j<=m;j++)
                if(op2.distance(i,j)<k)c++;
        
            mx=max(mx,c);
        }
        
        vector<int>ans;
        for(int i=1;i<=n;i++){
            int c=0;
        
            for(int j=1;j<=n;j++)
                if(op1.distance(i,j)<=k)c++;
        
            ans.push_back(c+mx);
        }
        
        return ans;
    }
};