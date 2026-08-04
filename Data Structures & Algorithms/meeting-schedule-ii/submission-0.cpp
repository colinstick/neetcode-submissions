/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int,int>> nums; //  1 for start 0 for end
        for(int i=0; i<intervals.size(); i++) {
            nums.push_back({intervals[i].start,1});
            nums.push_back({intervals[i].end, 0});
        }

        sort(nums.begin(), nums.end());

        int currMeetings = 0;
        int ans = 0; int i=0;
        while(i < nums.size()) {
            int curr = nums[i].first;
            while(i<nums.size() && nums[i].first == curr) {
                if(nums[i].second) currMeetings++;
                else currMeetings--;
                i++; 
            }
            ans = max(ans, currMeetings);
        }
        
        return ans;
    }
};
