class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>> arr;
        for(int i=0; i<strs.size(); i++) {
            string og = strs[i];
            sort(strs[i].begin(), strs[i].end());
            arr.push_back({strs[i], og});
        }
        sort(arr.begin(), arr.end());
        vector<vector<string>> ans;
        vector<string> temp;
        string category = arr[0].first;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i].first != category) {
                // new group
                category = arr[i].first;
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(arr[i].second);
        }
        ans.push_back(temp);
        return ans;
    }
};
