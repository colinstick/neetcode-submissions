class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 40 || s[i] == 91 || s[i] == 123) {
                st.push(s[i]);
            } else {
                // closing
                if(st.empty()) return false;
                if(s[i] == 41) {
                    if(st.top() != 40) return false;
                    st.pop();
                } else {
                    if(st.top() != s[i] - 2) return false;
                    st.pop();
                }
            }
        }

        return st.empty();
    }
};
