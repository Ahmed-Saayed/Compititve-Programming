class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>ans, ret;
        for(auto i : obstacles){
            if(!ans.size() || i >= ans.back())  
                ans.push_back(i);
            else 
                ans[upper_bound(ans.begin(), ans.end(), i) - ans.begin()] = i;

            ret.push_back(upper_bound(ans.begin(), ans.end(), i) - ans.begin());
        }

        return ret;
    }
};