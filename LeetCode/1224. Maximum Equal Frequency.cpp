class Solution {
public:
    int maxEqualFreq(vector<int>& x) {
        int ans,c=1;
    
        vector<int>tmp=x;
        sort(tmp.begin(),tmp.end());
        if(tmp[0]==tmp.back())return x.size();

        map<int,int>mp,fre;
        for(auto i:x){
            if(mp.count(fre[i])){
                mp[fre[i]]--;

                if(!mp[fre[i]])mp.erase(fre[i]);
            }

            fre[i]++;
            mp[fre[i]]++;

            if(mp.size()==2&&((mp.begin()->first==1&&mp.begin()->second==1)||((mp.rbegin()->first==mp.begin()->first+1&&mp.rbegin()->second==1)))||(mp.size()==1&&mp.begin()->first==1)||(mp.size()==1&&mp.begin()->first==2&&mp.begin()->second==1))
                ans=c;

            c++;
        }

        return ans;
    }
};