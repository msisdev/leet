#include "problems/p0057_insert_interval.hpp"

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        // push Is that doesn't overlap
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i += 1;
        }

        // push Is that overlap
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1] , intervals[i][1]);
            i += 1;
        }
        ans.push_back(newInterval);

        // push all
        while (i < n) {
            ans.push_back(intervals[i]);
            i += 1;
        }

        return ans;
    }
};

void run_p0057_demo() {
    // TODO: Add local demo cases if needed.
}
