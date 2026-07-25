#include "problems/p0219_contains_duplicate_ii.hpp"

#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int res = 0;

        for (int num : num_set) {
            if (!num_set.count(num - 1)) {
                int i = 1;

                while (num_set.count(num + i)) {
                    i += 1;
                }

                res = std::max(res, i);
            }
        }

        return (res);
    }
};

void run_p0128_demo() {
    // TODO: Add local demo cases if needed.
}
