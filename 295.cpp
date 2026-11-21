class MedianFinder {
private:
    priority_queue<int> small;                                  // max-heap
    priority_queue<int, vector<int>, greater<int>> large;      // min-heap
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        small.push(num);
        int val = 0;

        //all num small <= num in large
        if(!small.empty() && !large.empty() && small.top() > large.top()){
            val = small.top();
            small.pop();
            large.push(val);
        }

        // uneven size
        if(small.size() > large.size() + 1){
            val = small.top();
            small.pop();
            large.push(val);
        }
        if(large.size() > small.size() + 1){
            val = large.top();
            large.pop();
            small.push(val);
        }



    }
    
    double findMedian() {
        if(small.size() > large.size()){
            return small.top();
        }
        if(large.size() > small.size()){
            return large.top();
        }

        return ((small.top() + large.top())/2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
