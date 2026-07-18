#include "problems/p0169_majority_element.hpp"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int n : nums) {
            if (count == 0) {
                candidate = n;
            }
            count += (n == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

void run_p0169_demo() {
    Solution s;
    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
    cout << "[p0169] majority element: " << s.majorityElement(nums) << "\n";
}
