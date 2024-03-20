class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // array to store merged intervals
        vector<vector<int>> merged;
        int i = 0;

        // iterate through intervals until finding an interval whose end is before the start of 'newInterval', then add each of these intervals to the 'merged' vector and increment 'i' by 1
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            merged.push_back(intervals[i]);
            i++;
        }

        // 1. iterate through intervals as long as there are intervals left and the start of the current interval is less than or equal to the end of 'newInterval'
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            // 2. Update 'newInterval' to merge the current interval with 'newInterval' by taking the minimum start and maximum end values, then increment 'i'
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        // push newInterval in merged array
        merged.push_back(newInterval);

        // continue iterating through the remaining intervals, adding each of them to the 'merged' vector and incrementing 'i'.
        while (i < intervals.size()) {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }
};