#define all(v) (v).begin(),(v).end()

class Solution {
public:
    vector<array<int,3>>v;
    vector<int>dp;
    int n;
    int rec(int i=0){
        if(i==n)return 0;

        int&ret=dp[i];
        if(~ret)return ret;

        ret=rec(i+1);
        
        int l=i+1,r=n-1,m;
        while(l<=r){
            m=l+r>>1;

            (v[m][0]<v[i][1]?l=m+1:r=m-1);
        }

        return ret=max(ret,v[i][2]+rec(l));
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            n=startTime.size();

            dp=vector<int>(n,-1);
            v=vector<array<int,3>>(n);

            for(int i=0;i<n;i++)
                v[i]={startTime[i],endTime[i],profit[i]};

            sort(all(v));

            return rec();
    }
};