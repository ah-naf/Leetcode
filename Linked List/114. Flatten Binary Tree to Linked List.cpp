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
    TreeNode *tree = nullptr, *cur = nullptr;
    void preOrder(TreeNode *root) {
        if(root == nullptr) return;
        if(tree == nullptr) {
            TreeNode *temp = new TreeNode(root->val);
            tree = temp; cur = temp;
        } else {
            TreeNode *temp = new TreeNode(root->val);
            cur -> right = temp;
            cur = cur -> right;
        }
        preOrder(root -> left);
        preOrder(root -> right);
        
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        preOrder(root);
        *root = *tree;
    }
};
