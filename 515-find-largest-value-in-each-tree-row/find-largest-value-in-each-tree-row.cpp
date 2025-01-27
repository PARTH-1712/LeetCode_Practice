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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int mx = INT_MIN;
            int size = q.size();

            while(size--) {
                TreeNode* curr = q.front();
                q.pop();

                mx = curr->val > mx? curr->val : mx;    

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};