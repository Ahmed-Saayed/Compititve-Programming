double calc(int a,int b){
    return (a+1) / double(b+1) - (a) / double(b);
}

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>>pq;
        for(auto i : classes)pq.push({calc(i[0],i[1]), {i[0], i[1]}});

        while(extraStudents--){
            auto[cost, p] = pq.top(); pq.pop();

            p.first++, p.second++;
            pq.push({calc(p.first, p.second), {p.first, p.second}});
        }

        double ans = 0;
        while(pq.size())
            ans += pq.top().second.first / double(pq.top().second.second), pq.pop();

        return ans / classes.size();
    }
};