class Solution {
public:
    void twoSum(set<vector<int>> &ans, vector<int> &nums, int avoid) {
        // two sum minus the given thing, only sweep to the right
        vector<int> temp(3);
        temp[0] = nums[avoid];
        int l = avoid+1; int r = nums.size()-1;
        while(l < r) {
            if(nums[l]+nums[r] == -1*nums[avoid]) {
                // found pair
                temp[1] = nums[l]; temp[2] = nums[r];
                ans.insert(temp);
                l++; r--;
            } else if(nums[l]+nums[r] < -1*nums[avoid]) {
                l++;
            } else {
                r--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans; // set of triplets
        sort(nums.begin(), nums.end());
        for(int x=0; x<nums.size()-2; x++) {
            twoSum(ans, nums, x);
        }
        vector<vector<int>> ansfr(ans.begin(), ans.end());
        return ansfr;
    }
};
