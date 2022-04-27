/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp (const Interval& a, const Interval& b) {
        if (a.start == b.start) return a.end < b.end;
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};