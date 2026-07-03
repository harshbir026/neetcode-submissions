class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        calculateDepth(root, maxDiameter);
        return maxDiameter;
    }

private:
    // Helper function that returns depth, but updates maxDiameter along the way
    int calculateDepth(TreeNode* node, int& maxDiameter) {
        if (!node) return 0;
        
        // 1. Find the depth of left and right subtrees (Bottom-Up)
        int leftDepth = calculateDepth(node->left, maxDiameter);
        int rightDepth = calculateDepth(node->right, maxDiameter);
        
        // 2. Calculate the diameter AT THIS NODE and update the maximum found so far
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        
        // 3. Return the height of this subtree to the parent node
        return 1 + max(leftDepth, rightDepth);
    }
};