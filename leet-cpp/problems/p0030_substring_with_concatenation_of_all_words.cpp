#include "problems/p0030_substring_with_concatenation_of_all_words.hpp"

#include <vector>
#include <string>
#include <unordered_map>
#include <optional>

using namespace std;

class Window {
private:
    unordered_map<string, int> target_map;
    int target_count;
    unordered_map<string, int> window_map;
    int window_count;

public:
    Window(const unordered_map<string, int>& target_map, int target_count)
    : target_map(target_map), target_count(target_count), window_count(0) {}

    bool is_word_valid(string word) {
        return target_map.find(word) != target_map.end();
    }

    bool is_count_valid(string word) {
        return window_map[word] < target_map[word];
    }

    void push(string word) {
        window_map[word] += 1;
        window_count += 1;
    }

    void pop(string word) {
        window_map[word] -= 1;
        window_count -= 1;
    }

    bool is_complete() {
        return target_count == window_count;
    }

    void reset() {
        window_map.clear();
        window_count = 0;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int word_len = words[0].length();
        unordered_map<string, int> target_map;
        for (const string& word : words) {
            target_map[word] += 1;
        }
        
        for (int offset = 0; offset < words[0].length(); offset += 1) {
            Window window = Window(target_map, words.size());

            int left = offset;
            for (int right = left; right + word_len <= s.length(); right += word_len) {
                string word = s.substr(right, word_len);

                if (!window.is_word_valid(word)) {
                    // reset window
                    window.reset();
                    left = right + word_len;
                    continue;
                }

                if (!window.is_count_valid(word)) {
                    while (!window.is_count_valid(word)) {
                        window.pop(s.substr(left, word_len));
                        left += word_len;
                    }
                }

                window.push(word);

                if (window.is_complete()) {
                    ans.push_back(left);
                    window.pop(s.substr(left, word_len));
                    left += word_len;
                }
            }
        }
        return ans;
    }
};

void run_p0030_demo() {
    // TODO: Add local demo cases if needed.
}
