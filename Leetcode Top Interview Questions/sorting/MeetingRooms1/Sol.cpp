// if intervals is a class:

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

// comparing using comparator function
class Solution {
private:
        bool static comparator(const Interval &lhs , const Interval &rhs){
                 return lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end<rhs.end);
        }
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */

    bool canAttendMeetings(vector<Interval> &intervals) {
               if (intervals.empty()) {
            return true;
        }

        sort(intervals.begin(), intervals.end(), comparator); //

        for (size_t i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i].end > intervals[i + 1].start) { // overlapping
                return false;
            }
        }
        return true;
    }
};

// comparing using lambda operator

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */

    bool canAttendMeetings(vector<Interval> &intervals) {
               if (intervals.empty()) {
            return true;
        }
         
         // lambda operator
            sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
              return lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end<rhs.end);
         });

        for (size_t i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i].end > intervals[i + 1].start) { // overlapping
                return false;
            }
        }
        return true;
    }
};