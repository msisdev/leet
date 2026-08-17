#include "problems/p0117_populating_next_right_pointers_in_each_node_ii.hpp"

#include <vector>
#include <string>
#include <queue>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// copied from top 5% submission
class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;

        while (curr != nullptr) {
            Node dummy(0);
            Node* tail = &dummy;

            // Traverse current level using next pointers
            while (curr != nullptr) {

                // Add left child
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }

                // Add right child
                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next;
            }

            // Move to next level
            curr = dummy.next;
        }

        return root;
    }
};

void run_p0117_demo() {
    // TODO: Add local demo cases if needed.
}
