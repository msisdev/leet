#include "problems/p0025_reverse_nodes_in_k_group.hpp"

#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dum(0);
        dum.next = head;

        ListNode* prev = &dum;
        ListNode* end = &dum;

        int count = 0;
        while (end) {
            if (count == k) {
                // reverse(prev, end);

                ListNode* curr = prev->next;
                for (int i = 0; i < k - 1; i += 1) {
                    ListNode* next = curr->next;
                    curr->next = next->next;
                    next->next = prev->next;
                    prev->next = next;
                }

                prev = curr;
                end = curr;
                count = 0;
                continue;
            }

            count += 1;
            end = end->next;
        }

        return dum.next;
    }
};

void run_p0025_demo() {
    // TODO: Add local demo cases if needed.
}
