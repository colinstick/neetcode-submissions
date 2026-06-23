class Solution {
public:
    bool isHappy(int n) {
        set<int> found;
        while(found.find(n) == found.end()) {
            found.insert(n);
            // replace with sum of squares
            int newN=0;
            while(n > 0) {
                newN += (n%10)*(n%10);
                n /= 10;
            }
            n = newN;
        }
        return n==1;
    }
};
