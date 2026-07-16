class Solution {
public:

    string encode(vector<string>& strs) {
        // first char is num of strs (use pure ascii value)
        // then it goes m strs[0][0]...strs[0][m-1]
        int n = strs.size();
        string ans = "";
        for(int i=0; i<n; i++) {
            ans += (unsigned char)strs[i].length();
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i=0; i<s.length(); i++) {
            string temp = "";
            int m = i + (int)(unsigned char)s[i];
            i++;
            while(i <= m) {
                temp += s[i];
                i++;
            }
            ans.push_back(temp);
            i--;
        }
        return ans;
    }
};
