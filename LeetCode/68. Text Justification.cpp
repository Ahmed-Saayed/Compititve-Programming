class Solution {
public:
    string conv(vector<string>o){
        string ret;
        for(auto i:o)ret+=i;
        return ret;
    }

    vector<string> fullJustify(vector<string>& v, int mx) {
        vector<string>ans,o;
        int cnt=0;

        for(auto i:v){
            if(!o.size())
                o.push_back(i),cnt+=i.size();
            else{
                if(cnt+i.size()+1<=mx)
                    o.push_back(i),cnt+=i.size()+1;
                else{
                    string tmp;
                    if(o.size()==1){
                        tmp=conv(o);
                        while(tmp.size()<mx)tmp+=' ';
                    }
                    else{
                        cnt-=o.size()-1;
                        while(cnt<mx){
                            for(int j=1;j<o.size()&&cnt<mx;j++)o[j]=' '+o[j],cnt++;
                        }
                        tmp=conv(o);
                    }

                    ans.push_back(tmp),
                    o={i},cnt=i.size();
                }
            }
        }

        if(o.size()){
            int sm=0;
            for(int i=1;i<o.size();i++)
                o[i]=' '+o[i],sm+=o[i].size();
            
            string tmp=conv(o);
            tmp+=string(mx-tmp.size(),' ');
            ans.push_back(tmp);
        }

        return ans;
    }
};