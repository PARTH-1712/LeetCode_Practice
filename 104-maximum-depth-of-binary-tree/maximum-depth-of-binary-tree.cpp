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


void levelOrder(int &height, queue<TreeNode*> q) {
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp == NULL) {
            height++;
            if (!q.empty()) {
                q.push(NULL);
            }
            continue;
        }

        if (temp -> left) q.push(temp -> left);
        if (temp -> right) q.push(temp -> right);
    }
}

public:
    int maxDepth(TreeNode* root) {
        int maxHeight = 0;
        queue<TreeNode*> q;

        if (!root) return 0;
        q.push(root);
        q.push(NULL);

        levelOrder(maxHeight, q);
        
        return maxHeight;
    }
};