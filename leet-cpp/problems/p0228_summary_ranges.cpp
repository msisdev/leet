#include "problems/p0228_summary_ranges.hpp"

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string to_range(int a, int b) {
        if (a == b) {
            return to_string(a);
        }
        return to_string(a) + "->" + to_string(b);
    }

    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;

        if (nums.size() == 0) {
            return ret;
        }
        
        int left = 0;
        for (int right = 1; right < nums.size(); right += 1) {
            if (nums[right-1] + 1 == nums[right]) {
                continue;
            }

            // push range
            ret.push_back(to_range(nums[left], nums[right-1]));
            left = right;
        }
        ret.push_back(to_range(nums[left], nums[nums.size()-1]));
        return ret;
    }
};

void run_p0228_demo() {
    // TODO: Add local demo cases if needed.
}
