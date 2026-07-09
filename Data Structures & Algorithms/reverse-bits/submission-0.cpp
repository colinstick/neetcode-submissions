class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i=0; i<32; i++) {
            ans += n%2 * (1 << (31-i));
            n/=2;
        }
        return ans;
    }
};
