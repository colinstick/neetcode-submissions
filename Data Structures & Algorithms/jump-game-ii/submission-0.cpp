class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for(int i=0; i<n; i++) dp.push_back(1007);
        dp[0] = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] != 1001)
                for(int j=i+1; j<=nums[i]+i && j<n; j++) {
                    dp[j] = min(dp[i] + 1, dp[j]);
                }
        }
        return dp[n-1];
    }
};
