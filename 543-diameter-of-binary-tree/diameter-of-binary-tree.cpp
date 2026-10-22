class Solution {
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        
        int throughRoot = height(root->left) + height(root->right);

     
        int leftDiam  = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);

        return max({throughRoot, leftDiam, rightDiam});
    }
};