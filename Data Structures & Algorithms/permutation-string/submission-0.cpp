class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        
        map<char,int> ref;
        for(int i=0; i<s1.length(); i++) {
            ref[s1[i]]++;
        }

        map<char,int> curr;
        for(int i=0; i<s1.length(); i++) curr[s2[i]]++;


        if(ref==curr) return true;

        for(int i=s1.length(); i<s2.length(); i++) {
            curr[s2[i]]++;
            char temp = s2[i-s1.length()];
            curr[temp]--;
            if(curr[temp] == 0) curr.erase(temp);
            if(ref==curr) return true;
        }

        return false;
        
    }
};
