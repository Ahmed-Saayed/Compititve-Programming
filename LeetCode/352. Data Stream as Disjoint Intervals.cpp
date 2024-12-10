class SummaryRanges {
public:
    vector<int>fre;
    SummaryRanges() {
        fre=vector<int>((int)1e4+5);
    }
    
    void addNum(int val) {
        fre[val]=1;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        vector<int>v;

        for(int i=0;i<1e4+2;i++){
            if(fre[i])
                v.push_back(i);

            else if(v.size())
                ans.push_back(vector<int>{v[0],v.back()}),v={};
        }

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */