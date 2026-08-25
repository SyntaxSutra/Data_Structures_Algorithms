class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(),nums.end());

        int product = k ;

        while(present.count(product))
        {
            product += k;
        }

        return product;

        
    }
};