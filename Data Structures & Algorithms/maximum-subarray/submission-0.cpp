class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0; int r = 1; // [l,r)
        int ans = nums[l];
        int currSum = nums[l];
        while(l < r && r < n) {
            while(currSum > 0 && r < n) {
                currSum += nums[r]; r++;
                ans = max(currSum, ans);
            }

            if(r >= n) break;
            l = r;
            currSum = nums[l];
            ans = max(currSum, ans);
            r++;
        }
        return ans;
    }
};
