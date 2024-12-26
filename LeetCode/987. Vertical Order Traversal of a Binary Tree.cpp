class Solution {
public:
    vector<array<int,3>>v;
    void dfs(TreeNode* root,int row,int col){
        if(root == NULL)return;

        v.push_back({root->val,row,col});

        dfs(root->left,row+1,col-1),
        dfs(root->right,row+1,col+1);
    }
    
    static bool cmp(array<int,3>x,array<int,3>y){
        if(x[2]!=y[2])
            return x[2]<y[2];

        if(x[1]!=y[1])
            return x[1]<y[1];

        return x[0]<y[0];
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);

        sort(v.begin(),v.end(),cmp);

        vector<vector<int>>ans;
        map<int,vector<int>>mp;
        for(auto [a,b,c]:v)
            mp[c].push_back(a);

        for(auto [a,b]:mp)
            ans.push_back(b);

        return ans;
    }
};