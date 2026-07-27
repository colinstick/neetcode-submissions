class Solution {
public:
    unordered_set<int> s;
    int path(int x) {
        int ans = 0;
        while(s.contains(x)) {
            x++; ans++;
        }
        return ans;
    }
    int longestConsecutive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(!s.contains(nums[i]-1)) {
                // start of seq
                ans = max(ans, path(nums[i]));
            }
        }

        return ans;
    }
};
