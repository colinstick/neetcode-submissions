class MinStack {
public:
    vector<int> s;
    vector<int> mins; // [0, i] inclusive
    MinStack() {
        s.clear();
    }
    
    void push(int val) {
        if(mins.size() > 0)
            mins.push_back(min(mins[mins.size() - 1], val));
        else
            mins.push_back(val);
        s.push_back(val);
    }
    
    void pop() {
        s.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return s[s.size()-1];
    }
    
    int getMin() {
        return mins[mins.size()-1];
    }
};
