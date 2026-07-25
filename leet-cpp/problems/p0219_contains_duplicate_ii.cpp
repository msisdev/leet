#include "problems/p0219_contains_duplicate_ii.hpp"

#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

// Use fixed length window
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            if (window.count(nums[i])) {
                return true;
            }
            
            window.insert(nums[i]);
            
            // Keep window size at most k
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};

void run_p0219_demo() {
    // TODO: Add local demo cases if needed.
}
