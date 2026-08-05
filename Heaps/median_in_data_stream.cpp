/*probelm link - https://leetcode.com/problems/find-median-from-data-stream/ */

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num<=left.top())
        left.push(num);

        else
        right.push(num);

        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }

        else if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size())
        return (left.top()+right.top())/2.0;

        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/*
Maintain two heaps: a max heap for the smaller half and a min heap for the larger half. 
Insert each new number into the appropriate heap based on its value. Rebalance the heaps 
so their sizes differ by at most one. The median is either the top of the max heap (odd number of elements) 
or the average of both heap tops (even number of elements).
*/