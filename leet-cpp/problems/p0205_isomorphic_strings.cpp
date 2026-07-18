#include "problems/p0205_isomorphic_strings.hpp"

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> s_map(256, 0);
        vector<int> t_map(256, 0);
        for (int i = 0; i < s.length(); i += 1) {
            if (s_map[s[i]] != t_map[t[i]]) {
                return false;
            }

            s_map[s[i]] = i + 1;
            t_map[t[i]] = i + 1;
        }
        return true;
    }
};

void run_p0205_demo() {
    // TODO: Add local demo cases if needed.
}
