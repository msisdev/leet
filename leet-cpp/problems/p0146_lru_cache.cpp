#include "problems/p0146_lru_cache.hpp"

#include <vector>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int cap;

    // list<key>
    list<int> l;

    // map<key, <val, node>>
    unordered_map<int, pair<int, list<int>::iterator>> m;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);

        // miss
        if (it == m.end()) {
            return -1;
        }

        // hit
        l.splice(l.begin(), l, it->second.second);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);

        // miss
        if (it == m.end()) {
            // max cap
            if (l.size() == cap) {
                m.erase(l.back());
                l.pop_back();
            }

            // push new
            l.push_front(key);
            m[key] = {value, l.begin()};

            return;
        }

        // hit
        it->second.first = value;
        l.splice(l.begin(), l, it->second.second);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

void run_p0146_demo() {
    // TODO: Add local demo cases if needed.
}
