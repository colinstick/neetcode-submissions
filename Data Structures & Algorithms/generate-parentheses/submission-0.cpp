class Solution {
public:
    vector<string> ans;
    int N;
    void helper(string temp, int lc, int rc) {
        if(lc < rc || lc > N || rc > N) {
            // invalid
            return;
        }

        if(temp.length() >= N*2) {
            ans.push_back(temp);
            return;
        }

        helper(temp + '(', lc+1, rc);
        helper(temp + ')', lc, rc+1);
    }
    vector<string> generateParenthesis(int n) {
        N = n; ans.clear();
        helper("", 0, 0);
        return ans;
    }
};
