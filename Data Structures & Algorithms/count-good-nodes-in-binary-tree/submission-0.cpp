class Solution {
public:
    int cnt = 0;
    
    void goodies(TreeNode* root, int maxi) {
        if (!root) return;
        
        
        if (root->val >= maxi) {
            cnt++;
        }
        
        
        maxi = max(maxi, root->val);
        
        goodies(root->left, maxi);
        goodies(root->right, maxi);
    }
    
    int goodNodes(TreeNode* root) {
        
        goodies(root, INT_MIN);
        return cnt;
    }
};