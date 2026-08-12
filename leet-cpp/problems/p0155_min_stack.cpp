#include "problems/p0155_min_stack.hpp"

#include <vector>
#include <string>

using namespace std;

class MinStack {
private:
    vector<pair<int, int>> s;

public:
    MinStack() {}
    
    void push(int value) {
        if (s.empty()) {
            s.push_back({value, value});
        } else {
            s.push_back({value, min(value, s.back().second)});
        }
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

void run_p0155_demo() {
    // TODO: Add local demo cases if needed.
}
