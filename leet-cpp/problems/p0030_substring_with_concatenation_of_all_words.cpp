#include "problems/p0030_substring_with_concatenation_of_all_words.hpp"

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> map;
        for (char c : s) {
            map[c] += 1;
        }

        for (char c : t) {
            map[c] -= 1;
            if (map[c] == 0) {
                map.erase(c);
            }
        }

        return map.size() == 0;
    }
};

void run_p0030_demo() {
    // TODO: Add local demo cases if needed.
}
