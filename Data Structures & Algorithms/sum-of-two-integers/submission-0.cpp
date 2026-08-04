class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int c = 0;
        int factor = 0;
        while(a!=0 || b!=0 || c!=0) {
            int ax = a%2;
            int bx = b%2;
            // a^b^c
            ans += (ax^bx^c) << factor;
            cout << (ax^bx^c) << " ";
            // a&b | c&(a^b)
            c = ax&bx | c&(ax^bx);
            cout << c << "\n";
            a/=2; b/=2;
            factor++;
        }
        return ans;
    }
};
