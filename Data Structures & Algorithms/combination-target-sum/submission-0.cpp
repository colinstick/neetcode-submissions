class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int left, int i, vector<int> curr) {
        if(left == 0) {
            ans.push_back(curr);
            return;
        }
        if(left < 0 || i >= nums.size()) return;

        curr.push_back(nums[i]);
        helper(nums, left-nums[i], i, curr);
        curr.pop_back();
        helper(nums, left, i+1, curr);
        
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        ans.clear(); vector<int> temp;
        helper(nums, target, 0, temp);
        return ans;
    }
};
