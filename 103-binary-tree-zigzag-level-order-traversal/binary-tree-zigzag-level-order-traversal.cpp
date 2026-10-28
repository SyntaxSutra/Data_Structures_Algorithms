class Solution {
private:
    void dfs(TreeNode * node , int depth , vector<vector<int>> &result)
    {
        if(node == nullptr)
        {
            return ;
        }
        if(depth == result.size())
        {
            result.push_back({});
        }
        if(depth % 2 == 0)
        {
            result[depth] . push_back(node->val);
        }
        else
        {
            result[depth].insert(result[depth]. begin() , node ->val);

        }
        dfs(node->left , depth+1 , result);
        dfs(node->right , depth+1 , result);
    } 



public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root , 0 , result);
        return result;

        
    }
};