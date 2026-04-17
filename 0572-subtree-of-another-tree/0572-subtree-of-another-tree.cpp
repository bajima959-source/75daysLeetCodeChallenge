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
    // Check if two trees are identical
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s||!t) return false;

        return (s->val == t->val) &&
               isSameTree(s->left, t->left) &&
               isSameTree(s->right, t->right);
    }

    // Main function
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        // Check if trees match at current node
        if (isSameTree(root, subRoot)) return true;

        // Otherwise check left and right subtree
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};