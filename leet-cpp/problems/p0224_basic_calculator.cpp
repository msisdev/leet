#include "problems/p0224_basic_calculator.hpp"

#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        long long ans = 0;
        long long num = 0;
        int sign = 1;
        stack<int> st;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                ans += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                ans += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            } else if (c == ')') {
                ans += sign * num;
                num = 0;
                ans *= st.top(); st.pop();
                ans += st.top(); st.pop();
            }
        }
        ans += sign * num;
        
        return ans;
    }
};

void run_p0224_demo() {
    // TODO: Add local demo cases if needed.
}
