class Solution {
public:
    vector<int>y;
    int ok(int m){
        int ret=0,o=0,i=0;
        for(int i=1;i<y.size();i++){
            while(y[i]-y[o]>m)
                ret+=i-o-1,o++;
        }
        
        return ret+(y.size()-o)*(y.size()-o-1)/2;
    }
    int smallestDistancePair(vector<int>& x, int k) {
        sort(x.begin(),x.end());
        y=x;

        int l=0,r=x.back()-x[0],m;
        while(l<=r){
            m=l+r>>1;

            (ok(m)<k?l=m+1:r=m-1);
        }

        return l;
    }
};