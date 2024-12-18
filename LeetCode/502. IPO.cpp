#define all(v) (v).begin(),(v).end()

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();

        priority_queue<int>pq;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
            v[i]={capital[i],profits[i]};

        sort(all(v));

        int i=0;
        while(i<n&&k){
            while(i<n&&v[i].first<=w)
                pq.push(v[i].second),i++;

            if(pq.size()){
                w+=pq.top(),
                pq.pop(),k--;
            }
            else break;
        }

        while(pq.size()&&k--)
            w+=pq.top(),pq.pop();

        return w;
    }
};