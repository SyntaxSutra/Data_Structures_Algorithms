class Solution {
    int height(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        // Diameter passing through root
        int throughRoot = height(root->left) + height(root->right);

        // Diameter entirely in left or right subtree
        int leftDiam  = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);

        return max({throughRoot, leftDiam, rightDiam});
    }
};