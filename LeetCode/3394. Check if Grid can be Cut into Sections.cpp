class Solution {
public:
    bool Ok(vector<pair<int,int>>&v){
    int c1 = 1, mx = v[0].second;

        for(int i = 1; i < v.size() ;i++){
            if(v[i].first >= mx)
                c1++, mx = v[i].second;
            else
                mx = max(mx, v[i].second);
        }

        return c1 > 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>v, v2;
        for(auto i:rectangles){
            v.push_back({i[0], i[2]});
            v2.push_back({i[1], i[3]});
        }

        sort(v.begin(), v.end()),
        sort(v2.begin(), v2.end());

        return Ok(v) | Ok(v2);
    }
};