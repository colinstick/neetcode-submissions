class MedianFinder {
public:
    priority_queue<int> left; // max of left
    priority_queue<int, vector<int>, greater<int>> right; // min of right
    int count;
    MedianFinder() {
        count=0;
    }
    
    void addNum(int num) {
        right.push(num);
        if(left.size()!=0 && left.top() > right.top()) {
            // swap
            int x = left.top();
            int y = right.top();
            left.pop(); right.pop();
            right.push(x);
            left.push(y);
        }
        if(right.size()-1 > left.size()) {
            // unbalanced
            left.push(right.top());
            right.pop();
        }
        count++;
    }
    
    double findMedian() {
        if(count%2==0) {
            return (left.top()+right.top())/2.0;
        } else {
            return right.top();
        }
    }
};
