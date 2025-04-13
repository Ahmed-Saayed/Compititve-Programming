const int N=1e5+5;
vector<int>v,in,out,parent,seg;
vector<pair<int,int>>adj[N];
int timer;

void build(int node,int l,int r){
    if(l==r){
        seg[node]=v[l];
        return;
    }

    int m=(l+r)>>1;
    build(node*2,l,m),
    build(node*2+1,m+1,r);

    seg[node]=seg[node*2]+seg[node*2+1];
}

int get(int node,int l,int r,int lef,int righ){
    if(l>righ||r<lef)return 0;
    if(l>=lef&&r<=righ)return seg[node];

    int m=(l+r)>>1;
    return get(node*2,l,m,lef,righ)+get(node*2+1,m+1,r,lef,righ);
}

void update(int node,int l,int r,int id,int val){
    if(l>id||r<id)return;
    if(l==r){
        seg[node]=val;
        return;
    }

    int m=(l+r)>>1;
    update(node*2,l,m,id,val),
    update(node*2+1,m+1,r,id,val);

    seg[node]=seg[node*2]+seg[node*2+1];
}


map<pair<int,int>,int>mp;
void dfs(int node=1,int prev=0,int par=0,int we=0){
    if(!par&&node!=1)
        par=node;

    mp[{node,prev}]=mp[{prev,node}]=timer,
    in[node]=timer++,
    parent[node]=par,
    v.push_back(we);

    for(auto [a,b]:adj[node])
        if(a!=prev)
            dfs(a,node,par,b);

    out[node]=timer++,
    v.push_back(-we);
}

void init(int n){
        parent=in=out=vector<int>(n+1);
        seg=vector<int>(n*4*2+5),
        v.clear(),
        mp.clear(),
        timer=0;
        fill(adj,adj+n+1,vector<pair<int,int>>());
}

class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        init(n);

        for(auto i:edges){
            int a=i[0],b=i[1],c=i[2];

            adj[a].push_back({b,c}),
            adj[b].push_back({a,c});
        }

        if(n!=1)
            dfs(),
            build(1,1,v.size()-1);

        vector<int>ans;
        for(auto i:queries){

            int type=i[0];
            if(type==1){
                int a=i[1],b=i[2],c=i[3];

                if(in[a]>in[b])
                    swap(a,b);

                update(1,1,v.size()-1,in[b],c),
                update(1,1,v.size()-1,out[b],-c);
            }
            else{
                int node=i[1];

                if(n==1){
                    ans.push_back(0);
                    continue;
                }

                ans.push_back(get(1,1,v.size()-1,in[parent[node]],in[node]));
            }
        }

        return ans;
    }
};