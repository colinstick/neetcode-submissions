class Solution {
public:
    int binSearch(vector<int> &nums, int l, int r) {
        int mid = l + (r - l)/2;
        if(l==r) return nums[l];
        // checking mid to r
        if(nums[mid] > nums[r]) {
            // not sorted here, rotation point IS here
            l = mid+1;
        } else {
            // sorted here, rotation point NOT in this thingy
            r = mid;
        }
        return binSearch(nums, l, r);
    }
    int findMin(vector<int> &nums) {
        return binSearch(nums, 0, nums.size()-1);
    }
};
