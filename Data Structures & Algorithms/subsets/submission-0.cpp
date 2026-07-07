class Solution {
public:
    void generateSub(vector<vector<int>>& ans, vector<int>& curr, 
                    vector<int>& nums, int index) {
        
        if(index == nums.size()) {
            //done
            ans.push_back(curr);
            return;
        }
        // either add index or nah
        curr.push_back(nums[index]);
        generateSub(ans, curr, nums, index+1);
        curr.pop_back();
        generateSub(ans, curr, nums, index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateSub(ans, temp, nums, 0);
        return ans;
    }
};
