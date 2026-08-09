class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s) {
        int l=0; int r=s.length()-1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    void helper(string s, vector<string>& curr, int index, string running) {
        if(index >= s.length()) {
            // done
            if(running=="") {
                ans.push_back(curr);
            }
            return;
        }

        running += s[index];

        // split here IF running can be a palindrome ;)
        if(isPalindrome(running)) {
            curr.push_back(running);
            helper(s, curr, index+1, "");
            curr.pop_back();
        }

        // or dont split
        helper(s, curr, index+1, running);
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> temp;
        helper(s, temp, 0, "");
        return ans;
    }
};
