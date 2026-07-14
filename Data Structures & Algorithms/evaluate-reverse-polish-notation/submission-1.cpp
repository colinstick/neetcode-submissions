#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++) {
            string tok = tokens[i];

            if(tok == "+" || tok == "-" || tok == "*" || tok == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if(tok == "+") {
                    st.push(a+b);
                } else if(tok == "-") {
                    st.push(b-a);
                } else if(tok == "*") {
                    st.push(a*b);
                } else if(tok == "/") {
                    st.push(b/a);
                }
                continue;
            }

            // a num
            int x = stoi(tok);
            st.push(x);
        }
        return st.top();
    }
};
