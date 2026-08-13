class Solution {
public:
    int maxSubstring(string s, int k, char c) {
        // considering char c
        int n = s.length();
        int a = 0; int b = 0;
        int ans = 0; 
        while(a <= b && b < n) {
            
            // can move b?
            if(s[b] == c) {
                // yes
                b++;
            } else if(k > 0) {
                k--; b++;
            } else if(b==a){
                b++; a++;
            } else {
                if(s[a] != c) k++;
                a++;
            }
            ans = max(ans, b-a);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        for(int i='A'; i<='Z'; i++) {
            ans = max(ans, maxSubstring(s, k, i));
        }
        return ans;
    }
};
