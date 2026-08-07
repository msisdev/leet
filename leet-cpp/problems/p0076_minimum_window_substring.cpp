#include "problems/p0076_minimum_window_substring.hpp"

#include <array>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Window {
private:
    unordered_map<char, int> window_map;
    int window_count;
    unordered_map<char, int> target_map;
    int target_count;

public:
    Window(unordered_map<char, int> target_map, int target_count)
    : target_map(target_map), target_count(target_count) {}

    bool is_kind_ok(char c) {
        return target_map.find(c) != target_map.end();
    }

    bool is_complete() {
        return window_count == target_count;
    }

    void push(char c) {
        // accept any number of c
        window_map[c] += 1;

        // but count them strictly
        if (window_map[c] <= target_map[c]) {
            window_count += 1;
        }
    }

    void pop(char c) {
        window_map[c] -= 1;

        if (window_map[c] < target_map[c]) {
            window_count -= 1;
        }
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> target_map;
        for (char ch : t) {
            target_map[ch] += 1;
        }
        Window window = Window(target_map, t.length());

        array<int, 2> ans = {-1, -1};
        int left = 0;
        for (int right = 0; right < s.length(); right += 1) {
            char c = s[right];

            if (window.is_kind_ok(c)) {
                window.push(c);
            }

            while (window.is_complete()) {
                if (ans[0] == -1 || ans[1]-ans[0] > right-left) {
                    ans[0] = left;
                    ans[1] = right;
                }
                if (window.is_kind_ok(s[left])) {
                    window.pop(s[left]);
                }
                left += 1;
            }
        }

        if (ans[0] == -1) return "";
        return s.substr(ans[0], ans[1] - ans[0] + 1);
    }
};

void run_p0076_demo() {
    // TODO: Add local demo cases if needed.
}
