#include "problems/p0001_two_sum.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_of;

        vector<int> res = {0, 0};
        for (size_t i = 0; i < nums.size(); i += 1) {
            int v = nums[i];
            if (index_of.count(target - v)) {
                res[0] = index_of[target-v];
                res[1] = i;
                return res;
            }
            index_of[v] = i;
        }

        return res;
    }
};


void run_p0001_demo() {
    Solution s;
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;

    auto ans = s.twoSum(nums, target);
    if (ans.size() == 2) {
        std::cout << "[p0001] twoSum answer indexes: " << ans[0] << ", " << ans[1] << "\n";
    } else {
        std::cout << "[p0001] no answer\n";
    }
}
