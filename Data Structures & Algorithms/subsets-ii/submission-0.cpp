class Solution {
public:
    map<int, int> freq;
    vector<vector<int>> ans;
    void helper(int index, int currFreq, vector<pair<int,int>>& fq, vector<int>& temp) {
        if(index >= fq.size()) {
            // donezo
            ans.push_back(temp);
            return;
        }

        // if avalibile, choose curr
        if(fq[index].second > currFreq) {
            temp.push_back(fq[index].first);
            helper(index, currFreq+1, fq, temp);
            temp.pop_back();
        }

        // choose next one
        helper(index+1, 0, fq, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        vector<pair<int,int>> fq(freq.begin(), freq.end());
        vector<int> temp;
        helper(0, 0, fq, temp);
        return ans;
    }
};
