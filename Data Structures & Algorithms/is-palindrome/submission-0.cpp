class Solution {
public:
    bool isPalindrome(string s) {
        string realStr;
        for(int i=0; i<s.length(); i++) {
            if(65 <= s[i] && s[i] <= 90) s[i] += 32;
            if(97 <= s[i] && s[i] <= 122 ||
               48 <= s[i] && s[i] <= 57)
               realStr += s[i];
        }
        
        int n = realStr.length();
        int a = 0; int b = n-1;
        while(a < b) {
            if(realStr[a] != realStr[b]) return false;
            a++; b--;
        }
        return true;
    }
};
