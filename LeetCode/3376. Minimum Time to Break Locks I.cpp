#define ll long long

vector<int>arr;
ll n, k;
ll rec(ll mask = 0){
    if(mask == (1 << n) - 1)return 0;

    ll ret = 1e9 ,o=__builtin_popcount(mask), add = k * o + 1;

    for(int i = 0; i < n; i++){
        if(mask >> i & 1)continue;

        int cost = (arr[i] + add - 1) / add;
        ret = min(ret, cost + rec(mask | (1ll << i)));
    }

    return ret;
}

class Solution {
public:
    int findMinimumTime(vector<int>& v, int o) {
        n = v.size(), arr = v, k = o;
        return rec();
    }
};