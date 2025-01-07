int dx[4]{1,-1,0,0},dy[4]{0,0,1,-1},vis[12][12];
bool ok(int i,int j,int n,int m){
    return i>=0&&i<n&&j>=0&&j<m;
}

struct Trie{
    Trie *ch[26];
    int end;

    Trie(){
        memset(ch,0,sizeof ch);
        end=0;
    }

    void add(string s){
        auto *node=this;

        for(auto i:s){
            if(!node->ch[i-'a'])
                node->ch[i-'a']=new Trie();

            node=node->ch[i-'a'];
        }

        node->end=1;
    }
};

set<string>st;
void rec(int i,int j,vector<vector<char>>& board,Trie*tr,string s){
    vis[i][j]=1;

    for(int k=0;k<4;k++){
        int a=dx[k]+i,b=dy[k]+j;

        if(ok(a,b,board.size(),board[0].size())&&tr->ch[board[a][b]-'a']&&!vis[a][b])
            rec(a,b,board,tr->ch[board[a][b]-'a'],s+board[a][b]);
    }

    if(tr->end)
        st.insert(s);

    vis[i][j]=0;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;

        st.clear();
        Trie *tr=new Trie();
        for(auto i:words)tr->add(i);

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){

                if(tr->ch[board[i][j]-'a'])
                    rec(i,j,board,tr->ch[board[i][j]-'a'],string(1,board[i][j]));
            }

        for(auto i:st)ans.push_back(i);

        return ans;
    }
};