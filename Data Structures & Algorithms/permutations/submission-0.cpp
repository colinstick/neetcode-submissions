class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int>& curr) {
        if(nums.size() == curr.size()) {
            ans.push_back(curr); return;
        }

        for(int i=0; i<nums.size(); i++) {
            // valid
            if(find(curr.begin(), curr.end(), nums[i]) == curr.end()) {
                // pick it
                curr.push_back(nums[i]);
                helper(nums, curr);
                curr.pop_back();
            }
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        vector<int> temp;
        helper(nums, temp);
        return ans;
    }
};
