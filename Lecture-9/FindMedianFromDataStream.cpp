// Problem Link : https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> Max; // By default its Max heap
    priority_queue<int,vector<int>,greater<int>> Min; // This is how we create Min heap
    
    void addNum(int num) {
        Max.push(num);
        Min.push(Max.top());
        Max.pop();
        if(Min.size()>Max.size()){
            Max.push(Min.top());
            Min.pop();
        }
    }
    
    double findMedian() {
        if((Min.size() + Max.size())%2 == 0){
            double ans = (double)(Min.top()+Max.top())/2;
            return ans;
        }
        return Max.top();
    }
};
