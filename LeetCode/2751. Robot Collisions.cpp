class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)v[i]={positions[i],i};

        sort(v.begin(),v.end());
        stack<int>st;

        for(auto[i,id]:v){
            if(directions[id]=='R'){
                st.push(id);
                continue;
            }

            while(st.size()){
                if(healths[id]==healths[st.top()]){
                    healths[id] = healths[st.top()] = 0;
                    st.pop();
                    break;
                }

                if(healths[id]>healths[st.top()]){
                    healths[id]-- ,healths[st.top()] = 0;
                    st.pop();
                }
                else{
                    healths[st.top()]--;
                    healths[id]=0;
                    break;
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
            if(healths[i])ans.push_back(healths[i]);

        return ans;
    }
};