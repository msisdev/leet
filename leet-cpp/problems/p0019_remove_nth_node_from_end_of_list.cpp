#include "problems/p0019_remove_nth_node_from_end_of_list.hpp"

#include <vector>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        {
            ListNode* p = head;
            while (p) {
                p = p->next;
                size += 1;
            }
        }

        if (n == size) {
            ListNode* ret = head->next;
            delete head;
            return ret;
        }

        ListNode* prev = head;
        for (int i = 1; i < size - n; i += 1) {
            prev = prev->next;
        }

        ListNode* drop = prev->next;
        prev->next = drop->next;
        delete drop;

        return head;
    }
};

void run_p0019_demo() {
    // TODO: Add local demo cases if needed.
}
