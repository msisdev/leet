#include "problems/p0290_word_pattern.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using std::string;

// pattern = "abbc"
// s = "apple banana banana cat"
// s = "apple banana bird cat"
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        std::unordered_map<char, std::string> word_map;
        std::unordered_set<std::string> word_set;

        for (int i = 0; i < pattern.size(); i += 1) {
            char p = pattern[i];
            std::string w = words[i];

            // `p` is already mapped
            if (word_map.count(p)) {
                if (word_map[p] != w) {
                    return false;
                }
            }
            // `p` is a new one
            else {
                // `w` is already mapped
                if (word_set.count(w)) {
                    return false;
                }

                word_map[p] = w;
                word_set.insert(w);
            }
        }

        return true;
    }
};

void run_p0290_demo() {
    // TODO: Add local demo cases if needed.
}
