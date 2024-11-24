#define ll long long 
class Solution {
public:
   
    long long maxMatrixSum(vector<vector<int>>& x) {
  
    ll neg=0,sum=0,small=1e9;

    for(auto i:x)
     for(auto j:i){
        if(j<0)neg++;

        sum+=abs(j),small=min(small,(ll)abs(j));
     }
    return (neg%2?sum-small*2:sum);
    }
};