#include "problems/p0173_binary_search_tree_iterator.hpp"

#include <vector>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    vector<TreeNode*> st;

    void push_left(TreeNode* node) {
        while (node) {
            st.push_back(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        push_left(root);
    }
    
    int next() {
        TreeNode* node = st.back(); st.pop_back();
        int ret = node->val;
        if (node->right) {
            push_left(node->right);
        }
        return ret;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

void run_p0173_demo() {
    // TODO: Add local demo cases if needed.
}
