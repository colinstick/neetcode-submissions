class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> myNums(n);
        for(int i=0; i<n; i++) {
            myNums[i] = {nums[i], i};
        }

        sort(myNums.begin(), myNums.end());

        int a = 0; int b = n - 1;
        while(myNums[a].first + myNums[b].first != target) {
            if(myNums[a].first+myNums[b].first < target) {
                a++;
            } else {
                b--;
            }
        }
        vector<int> ans = {myNums[a].second, myNums[b].second};
        sort(ans.begin(), ans.end());
        return ans;
    }
};
