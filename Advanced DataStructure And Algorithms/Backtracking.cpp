class Solution {
public:
set<vector<vector<char>>>s;
void rec(int i,vector<vector<char>>grid){		//52. N-Queens II
    if(i==grid.size()){
        s.insert(grid);
        return;
    }

for(int j=0;j<grid.size();j++){
    int o=j,p=1;
    for(int k=i;~k&&o<grid.size()&&p;k--)
        if(grid[k][o++]!='.')p=0;
    
    o=j;
    for(int k=i;~k&&~o&&p;k--)
        if(grid[k][o--]!='.')p=0;
    
    for(int k=i;~k&&p;k--)
        if(grid[k][j]!='.')p=0;

    if(p){
        grid[i][j]='Q';
        rec(i+1,grid);
        grid[i][j]='.';
    }
}
}

    int totalNQueens(int n) {
        vector<vector<char>>grid(n,vector<char>(n,'.'));
        rec(0,grid);

        return s.size();
    }
};