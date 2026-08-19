#include "problems/p0129_sum_root_to_leaf_numbers.hpp"

#include <vector>
#include <string>
#include <cmath>

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
    int dfs(TreeNode* node, int sum) {
        if (!node) {
            return 0;
        }

        sum *= 10;
        sum += node->val;

        if (!node->left && !node->right) {
            return sum;
        }

        return dfs(node->left, sum) + dfs(node->right, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

void run_p0129_demo() {
    // TODO: Add local demo cases if needed.
}
