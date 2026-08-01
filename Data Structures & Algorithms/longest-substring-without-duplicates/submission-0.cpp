class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_map<char,int> freq;
        for(int i=0; i<256; i++) freq[(char)i]=0;
        int l=0; int r=1;
        int ans=1;
        freq[s[l]]++;
        while(l<r && r<s.length()) {
            if(freq[s[r]]>0) {
                // nope
                while(freq[s[r]]>0) {
                    freq[s[l]]--; l++;
                }
            }
            freq[s[r]]++; r++;
            ans = max(ans, r-l);
        }
        return ans;
    }
};
