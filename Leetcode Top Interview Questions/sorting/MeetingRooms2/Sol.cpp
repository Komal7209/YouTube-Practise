//if interval is a class
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
    //
    // * @param intervals: an array of meeting time intervals
    // * @return: the minimum number of conference rooms required
    // *
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
   // }
     //   int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &t : intervals)
            m[t.start]++, m[t.end]--;
        int cur = 0, res = 0;
        for (auto &it : m)
            res = max(res, cur += it.second);
        return res;
    }
};  
