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
private:
    vector<TreeNode*>forest;
    unordered_set<int> toDeleteSet;
    TreeNode*dfs(TreeNode*node)
    {
        if(!node)
        {
            return nullptr;
        }
        node->left = dfs(node->left);
        node->right = dfs(node->right);
        if(toDeleteSet.count(node->val))
        {
            if(node->left)
            {
                forest.push_back(node->left);
            }
            if(node->right)
            {
                forest.push_back(node->right);
            }
            delete node;
            return nullptr;
        }
        return node;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        forest.clear();
        toDeleteSet = unordered_set<int>(to_delete.begin(), to_delete.end());
        root = dfs(root);
        if(root)
        {
            forest.push_back(root);
        }
        return forest;
        
    }
};