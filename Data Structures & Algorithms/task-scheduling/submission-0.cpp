class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {}; n++;
        for(int c : tasks) {
            freq[c-65]++;
        }
        vector<int> nums;
        for(int i=0; i<26; i++) {
            if(freq[i] != 0)
                nums.push_back(freq[i]);
        }
        int k = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        // count how many maxes
        int yuh=nums[0]; int tempfreq=0;
        for(int i=0; i<k; i++) {
            if(nums[i]==yuh) tempfreq++;
            else break;
        }
        
        return max((int)tasks.size(), yuh*n-(n-tempfreq));

    }
        
};
