#include "problems/p0452_minimum_number_of_arrows_to_burst_ballons.hpp"

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_overlapped(const vector<int>& a, const vector<int>& b) {
    return b[0] <= a[1];
}

void get_inter(vector<int>& a, const vector<int>& b) {
    a[0] = (max(a[0], b[0]));
    a[1] = (min(a[1], b[1]));
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int i = 0;
        while (i < points.size()) {
            int end = points[i][1];
            i += 1;
            while (i < points.size() && points[i][0] <= end) {
                i += 1;
            }

            ans += 1;
        }

        return ans;
    }
};

void run_p0452_demo() {
    // TODO: Add local demo cases if needed.
}
