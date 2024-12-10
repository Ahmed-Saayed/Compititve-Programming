class MedianFinder {
public:
    priority_queue<int>pq;
    priority_queue<int, vector<int>, greater<>>pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        
        while(pq2.size() < pq.size())
            pq2.push( pq.top() ), pq.pop();

        if(pq.size() && pq2.size() && pq2.top() < pq.top()){
                pq2.push(pq.top()),
                pq.pop(),
                pq.push(pq2.top()),
                pq2.pop();
        }
    }
    
    double findMedian() {
        if((pq.size()  + pq2.size()) % 2)
            return pq2.top();
        else 
            return (pq.top() + pq2.top()) / 2.0;
    }
};