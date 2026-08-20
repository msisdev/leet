#include "problems/p0124_binary_tree_maximum_path_sum.hpp"

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

// left-this-right: 확장 없음
// left-this | this-right: 확장가능
class Solution {
    int max_sum = INT32_MIN;

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }

        // drop negative value
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // compare max with path left_node_right
        max_sum = max(max_sum, node->val + left + right);

        // return expandable path: left_node or node_right
        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};

void run_p0124_demo() {
    // TODO: Add local demo cases if needed.
}
