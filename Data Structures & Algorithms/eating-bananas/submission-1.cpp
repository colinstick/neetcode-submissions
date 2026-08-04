class Solution {
public:
    bool valid(vector<int>& p, int k, int h) {
        // does k work?
        int ans=0;

        for(int i=0; i<p.size(); i++) {
            ans += (p[i]+k-1)/k;
            if(ans > h) return false;
        }
        return true;
    }
    int binSearch(vector<int>& p, int min, int max, int h) {
        int l=min; int r=max;
        while(l<r) {
            int mid = l+(r-l)/2;
            if(valid(p, mid, h)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        return binSearch(piles, 1, 1e9, h);
    }
};
