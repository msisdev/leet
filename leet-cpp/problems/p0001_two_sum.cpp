#include "problems/p0001_two_sum.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> index_of;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int need = target - nums[i];
            auto it = index_of.find(need);
            if (it != index_of.end()) {
                return {it->second, i};
            }
            index_of[nums[i]] = i;
        }
        return {};
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
