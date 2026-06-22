class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // track minimum
        int ans = 0;
        int currMin = prices[0];
        // sell on i
        for(int i=1; i<n; i++) {
            ans = max(ans, prices[i] - currMin);
            currMin = min(currMin, prices[i]);
        }
        return ans;
    }
};
