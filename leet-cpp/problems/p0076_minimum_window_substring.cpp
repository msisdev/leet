#include "problems/p0076_minimum_window_substring.hpp"

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> target_count;
        for (const ch : t) {
            target_count[ch] += 1;
        }

        int left = 0;
        int right = 0;
        unordered_map<int, int> window_count;
        string min_sub = "";
        while (right < s.length()) {
            
        }
    }
};

void run_p0076_demo() {
    // TODO: Add local demo cases if needed.
}
