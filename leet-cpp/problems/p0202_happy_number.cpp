#include "problems/p0202_happy_number.hpp"

#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    int squareSum(int n) {
        int res = 0;
        while (n > 0) {
            res += pow(n % 10, 2);
            n /= 10;
        }
        return (res);
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while (n != 1 && fast != 1) {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
            if (slow == fast && fast != 1) {
                return (false);
            }
        }

        return (true);
    }
};

void run_p202_demo() {
    // TODO: Add local demo cases if needed.
}
