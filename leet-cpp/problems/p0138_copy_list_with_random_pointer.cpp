#include "problems/p0138_copy_list_with_random_pointer.hpp"

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> index_of;
        unordered_map<int, int> map;

        Node* p = head;
        int i = 0;
        while (p) {
            index_of[p] = i;
            
            p = p->next;
            i += 1;
        }
        int size = i;

        p = head;
        for (int i = 0; i < size; i += 1) {
            if (p->random) {
                map[i] = index_of[p->random];
            }
            else {
                map[i] = -1;
            }
            p = p->next;
        }
        
        unordered_map<int, Node*> node_of;
        p = head;
        Node dum = Node(0);
        Node* q = &dum;
        for (int i = 0; i < size; i += 1) {
            q->next = new Node(p->val);
            node_of[i] = q->next;
            p = p->next;
            q = q->next;
        }

        q = dum.next;
        for (int i = 0; i < size; i += 1) {
            if (map[i] == -1) {
                q->random = NULL;
            }
            else {
                q->random = node_of[map[i]];
            }
            q = q->next;
        }

        return dum.next;
    }
};

void run_p0138_demo() {
    // TODO: Add local demo cases if needed.
}
