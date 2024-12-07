#define ll long long
bool prime(int n){
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)return 0;

    return n != 1;
}

class Solution {
public:
    int minOperations(int n, int m) {
        priority_queue<pair<int ,string>,vector<pair<int ,string>>, greater<>>pq;
        string s = to_string(n),e = to_string(m);

        vector<int>dis((ll)1e4+5, 1e9);

        if(prime(n))return -1;

        pq.push({n, s});
        while(pq.size()){
            auto[cost, node] = pq.top(); pq.pop();

            if(node == e)return cost;

            for(int i=0;i<node.size();i++){
                if(node[i]!='9'){
                    node[i]++;

                    int num = stoi(node);
                    if(!prime(num) && cost + num < dis[num])
                        dis[num] = cost + num, pq.push({cost + num, node});

                    node[i]--;
                }

                if(node[i] != '0'){
                    node[i]--;

                    int num = stoi(node);
                    if(node[0] != '0' && !prime(num) && cost + num < dis[num])
                        dis[num] = cost + num, pq.push({cost + num, node});

                    node[i]++;
                }

            }
        }

        return -1;
    }
};
