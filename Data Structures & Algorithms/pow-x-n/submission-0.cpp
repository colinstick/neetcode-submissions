class Solution {
public:
    double myPow(double x, int n) {
        if(x==0 && n==0) return 0.0;
        if(n==0) return 1.0;
        if(n > 0) {
            double ans = 1;
            for(int i=0; i<n; i++) ans *= x;
            return ans;
        } else {
            double ans = 1;
            return 1.0 / myPow(x, -1*n);
        }
    }
};
