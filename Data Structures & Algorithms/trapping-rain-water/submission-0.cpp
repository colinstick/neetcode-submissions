class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft[1007];
        int maxRight[1007];
        int n = height.size();
        maxLeft[0] = 0;
        for(int i=1; i<n; i++) {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        maxRight[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += max(0,min(maxLeft[i], maxRight[i]) - height[i]);
        }

        return ans;
    }
};
