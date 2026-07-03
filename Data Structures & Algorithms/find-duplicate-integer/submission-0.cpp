class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int curr = nums[i];
            if(curr < 0) curr *= -1;
            if(nums[curr-1] < 0) return curr;
            nums[curr-1] *= -1;
        }
        return -1;
    }
};
