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
    int maxDepth(TreeNode* node){
        if(!node) return 0;
        return 1 + max(maxDepth(node->left),maxDepth(node->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int dia =  maxDepth(root->left)+maxDepth(root->right);
        dia = max(dia,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        return dia;
    }
};