class Solution {
public:

    pair<int, int>Finding_The_IndexOf_cell(vector<vector<int>>board){
           int x,y;
            for(int i = 0; i < 2 ;i++)
                for(int j = 0;j < 3; j++)
                   if(!board[i][j])x = i, y = j;
        
          return {x, y};
    }

    int slidingPuzzle(vector<vector<int>>& board) {

        int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1}; 
        map<vector<vector<int>> ,int>vis;
        queue<vector<vector<int>>>q;
        q.push(board);
        
        while(q.size()){                
            auto cur_board = q.front(); q.pop();

             if(cur_board[0][0] == 1 &&    
                cur_board[0][1] == 2 && 
                cur_board[0][2] == 3 && 
                cur_board[1][0] == 4 && 
                cur_board[1][1] == 5 && 
                !cur_board[1][2]){
                     return vis[cur_board];
                }

            auto last_board = cur_board;
            auto [x,y] = Finding_The_IndexOf_cell(cur_board);

            for(int i = 0;i < 4; i++){                      
                int x2 = x + dx[i] , y2 = y + dy[i];
            
                if(x2 >= 0 && x2 < 2 && y2 >= 0 && y2 < 3){
                    swap(cur_board[x][y], cur_board[x2][y2]);   

                    if(!vis.count(cur_board)){
                        vis[cur_board] = vis[last_board] + 1, 
                        q.push(cur_board);
                    }

                    swap(cur_board[x][y], cur_board[x2][y2]);  
                }
            }
        }

        return -1;
    }
};