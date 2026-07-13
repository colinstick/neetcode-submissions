class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        vector<vector<int>> buckets(n+1);
        for(auto x : freq) {
            buckets[x.second].push_back(x.first);
        }
        vector<int> ans;
        int i = n;
        while(k > 0) {
            if(buckets[i].size() > 0) {
                k--;
                ans.push_back(buckets[i].back());
                buckets[i].pop_back();
            } else {
                i--;
            }
        }
        
        return ans;

    }
};
