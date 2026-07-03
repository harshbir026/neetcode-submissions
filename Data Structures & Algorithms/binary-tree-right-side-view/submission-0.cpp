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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        unordered_set<int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<int> res;
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int y = q.front().second;
            q.pop();
            if (mpp.find(y) == mpp.end()) {
                mpp.insert(y);
                res.push_back(node->val);
            }
            if(node->right){
                q.push({node->right,y-1});
            }
            if(node->left){
                q.push({node->left,y-1});
            }
        }
        
       return res; 
    }
};
