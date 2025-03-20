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
class Solution {
public:
    int getDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int val1 = getDepth(root->left) + 1;
        int val2 = getDepth(root->right) + 1;

        return max(val1, val2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int val1 = getDepth(root->left);
        int val2 = getDepth(root->right);

        return max(val1 + val2, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};