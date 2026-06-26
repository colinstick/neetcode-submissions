class KthLargest {
public:
    priority_queue<int> pq;
    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i=0; i<nums.size(); i++)
            pq.push(nums[i]);    
    }
    
    int add(int val) {
        pq.push(val);
        int count=0; int ans=-1;
        priority_queue<int> pq_copy = pq;
        while(count < K) {
            count++;
            ans = pq_copy.top();
            pq_copy.pop();
        }
        return ans;
    }
};
