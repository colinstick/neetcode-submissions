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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> fr(n);
        for(int i=0; i<n; i++) {
            fr[i] = {intervals[i].start, intervals[i].end};
        }
        sort(fr.begin(), fr.end());
        for(int i=1; i<n; i++) {
            if(fr[i].first < fr[i-1].second) return false;
        }
        return true;
        
    }
};
