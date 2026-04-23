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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;

        while (true) {
            // Go to leftmost node
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }

            // Process node
            root = st.top();
            st.pop();
            k--;

            if (k == 0) return root->val;

            // Move to right subtree
            root = root->right;
        }
    }
};
