class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& x) {
        vector<vector<int>>v;
        for(auto i:x){
            int o=0;          
            v.push_back({});

            for(auto j:i){
                if(j=='.')v.back().push_back(0);
                else if(j=='#')v.back().push_back(1);
                else{
                    sort(v.back().begin()+o,v.back().end()),
                    v.back().push_back(2),
                    o=v.back().size();
                }
            }
            sort(v.back().begin()+o,v.back().end());
        }

    reverse(v.begin(),v.end());

    vector<vector<char>>ans;
    for(int i=0;i<x[0].size();i++){
        ans.push_back({});

        for(int j=0;j<x.size();j++){
            if(!v[j][i])ans.back().push_back('.');
            else if(v[j][i]==1)ans.back().push_back('#');
            else ans.back().push_back('*');
        }
    }

    return ans;
    
    }
    
};