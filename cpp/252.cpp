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
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {

        if (intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){
            return a.start < b.start;
        });

        for(int i = 0; i + 1 < intervals.size(); i++){
            if(intervals[i].end > intervals[i+1].start){
                return false;
            }
        }
        return true;
    }
};
