#include "problems/p0056_merge_intervals.hpp"

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_mergeable(const vector<int>& a, const vector<int>& b) {
    return b[0] <= a[1];
}

vector<int> merge_two(const vector<int>& a, const vector<int>& b) {
    vector<int> ret;

    ret.push_back(a[0]);
    ret.push_back(max(a[1], b[1]));
    return ret;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        vector<int> last = intervals[0];
        for (int i = 1; i < intervals.size(); i += 1) {
            vector<int>& cur = intervals[i];
            if (is_mergeable(last, cur)) {
                last = merge_two(last, cur);
            }
            else {
                ans.push_back(last);
                last = cur;
            }
        }
        ans.push_back(last);

        return ans;
    }
};

void run_p0056_demo() {
    // TODO: Add local demo cases if needed.
}
