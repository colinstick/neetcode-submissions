class Solution {
public:
    vector<string> ans;
    map<int, string> dmap = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    void comboHelper(string& curr, string& digits) {
        if(digits.length() == 0) return;
        if(curr.length() == digits.length()) {
            ans.push_back(curr);
            return;
        }
        int theDigit = digits[curr.length()]-48;
        for(int i=0; i<dmap[theDigit].length(); i++) {
            // each char
            string oldCurr = curr;
            curr = curr + dmap[theDigit][i];
            comboHelper(curr, digits);
            curr = oldCurr;
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        ans.clear();
        string temp = "";
        comboHelper(temp, digits);
        return ans;
    }
};
