class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[100][2]; // rob iths house yes or rob ith house nah
        dp[0][0] = 0; dp[0][1] = nums[0];
        for(int i=1; i<n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            int temp;
            if(i < 2) temp = 0;
            else temp = dp[i-2][1];
            dp[i][1] = max(dp[i-1][0], temp) + nums[i];
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};
