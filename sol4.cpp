/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */ 



 bool myCmp(Interval a, Interval b) {
            return a.start < b.start;
        }

        vector<Interval> merge(vector<Interval> &intervals) {
            if(intervals.size() < 2) {
                return intervals;
            }
            sort(intervals.begin(), intervals.end(), myCmp);
            int first = 0;
            for(int i = 1; i < intervals.size(); i++) {
                // There is overlap in intervals at first and i position.
                if(intervals[i].start <= intervals[first].end) {
                    // We merge the i interval into the first one and modify the first interval to reflect it. 
                    intervals[first].end = max(intervals[i].end, intervals[first].end);
                }
                else {
                    // No overlap between first and i. Move forward. 
                    ++first;
                    intervals[first].start = intervals[i].start;
                    intervals[first].end = intervals[i].end;
                }
            }
            intervals.erase(intervals.begin() + first + 1, intervals.end());
            return intervals;
        }
