struct Trie{

    Trie*ch[26];
    int pre,out;

    Trie(){
        pre=0,out=0;
        memset(ch,0,sizeof ch);
    }

    void in(string s){
        auto*cur=this;

        for(auto i:s){
            int id=i-'a';

            if(cur->ch[id]==0)
                cur->ch[id]=new Trie();

            cur=cur->ch[id],
            cur->pre++;
        }
        cur->out++;
    }

    bool cnt(string s){
        auto*cur=this;
        for(auto i:s){
            int id=i-'a';

            if(cur->ch[id]==0)return 0;

            cur=cur->ch[id];
        }

        return cur->out!=0;
    }
};