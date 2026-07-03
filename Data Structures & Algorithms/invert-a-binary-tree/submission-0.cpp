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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                TreeNode* left = node->left;
                TreeNode* right = node->right;
                if(node->left){
                    
                    q.push(left);
                }
                if(node->right){
                    
                    q.push(right);
                }
                node->left = right;
                node->right = left;
            }
        }
        return root;
    }
};
