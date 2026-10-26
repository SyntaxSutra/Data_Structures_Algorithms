#include <vector>
using namespace std;

class Solution {
    void dfs(TreeNode* node, int depth, vector<int>& result) 
    {
        if (!node) return;

        if (depth == result.size()) 
        {
            result.push_back(node->val);
        }
        dfs(node->right, depth + 1, result);
        dfs(node->left, depth + 1, result);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};