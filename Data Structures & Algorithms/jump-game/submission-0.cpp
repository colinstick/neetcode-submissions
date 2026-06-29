class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int i = 0;
        while(maxJump < nums.size()-1 && i < nums.size()) {
            if(maxJump < i) return false;
            maxJump = max(maxJump, i+nums[i]);
            i++;
        }
        return true;
        
    }
};
