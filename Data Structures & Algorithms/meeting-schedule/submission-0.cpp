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
    static bool comp(Interval a , Interval b){
        return a.end <= b.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(),intervals.end(),comp);
            int endtime = intervals[0].end;
        for(int i = 1;i < intervals.size();i++){
            if(endtime <= intervals[i].start){
                endtime = intervals[i].end;
            } 
            else return false;     
        }
        return true;
    }
};
