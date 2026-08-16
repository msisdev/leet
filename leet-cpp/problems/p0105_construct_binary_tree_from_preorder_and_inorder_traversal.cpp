#include "problems/p0105_construct_binary_tree_from_preorder_and_inorder_traversal.hpp"

#include <vector>
#include <string>
#include <unordered_map>

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

class Solution {
private:
    int preorder_index = 0;
    unordered_map<int, int> in_of;  // map<key, inorder_index>

public:
    TreeNode* _build(vector<int>& preorder, vector<int>& inorder, pair<int, int> range) {
        if (range.second < range.first) {
            return NULL;
        }

        int root_key = preorder[preorder_index++];
        int root_index = in_of[root_key];

        TreeNode* root = new TreeNode(root_key,
            _build(preorder, inorder, {range.first, root_index-1}),
            _build(preorder, inorder, {root_index+1, range.second}));

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        preorder_index = 0;
        in_of.clear();

        for (int i = 0; i < size; i += 1) {
            in_of[inorder[i]] = i;
        }

        return _build(preorder, inorder, {0, size - 1});
    }
};

void run_p0105_demo() {
    // TODO: Add local demo cases if needed.
}
