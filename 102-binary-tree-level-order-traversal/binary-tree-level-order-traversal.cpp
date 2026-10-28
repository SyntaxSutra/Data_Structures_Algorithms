class Solution {
private:
   void dfs(TreeNode* node , int depth , vector<vector<int>> &result)
   {
    if(node == nullptr)
    {
        return ;
    }
    if(depth == result.size())
    {
        result.push_back({});
    }
    result[depth].push_back(node->val);
    dfs(node->left , depth+1 , result);
    dfs(node->right , depth+1 , result);
   }







public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root , 0 ,result);
        return result;
        
    }
};