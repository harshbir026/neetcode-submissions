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
    bool isValid(TreeNode* root,int minBound,int maxBound){
        if(!root) return true;
        if(root->val<=minBound || root->val>=maxBound ){
            return false;
        }
        return isValid(root->left,minBound,root->val) && isValid(root->right,root->val,maxBound);
    }
    bool isValidBST(TreeNode* root) {
        
        return isValid(root,INT_MIN,INT_MAX);
    }
};
