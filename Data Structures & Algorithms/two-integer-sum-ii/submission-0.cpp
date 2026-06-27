class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int a = 0; int b = n - 1;
        while(a < b) {
            if(numbers[a] + numbers[b] < target) a++;
            else if(numbers[a] + numbers[b] > target) b--;
            else break;
        }
        return {a+1,b+1};
    }
};
