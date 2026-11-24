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
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        vector<int> starts;
        vector<int> ends;

        for(int i = 0; i < intervals.size(); i++){
            starts.push_back(intervals[i].start);
            ends.push_back(interval[i].end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int res = 0, count = 0;
        int s = 0, e = 0;

        while(s < intervals.size()){
            if(starts[s] < ends[e]){
                s++;
                count++;
            } else {
                e++;
                count--;
            }
            res = max(res, count);
        }
        return res;
        
    }
};
