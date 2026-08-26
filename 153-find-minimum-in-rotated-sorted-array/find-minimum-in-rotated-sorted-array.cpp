class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minVal = nums[0];
        for(int i =1;i<n;i++)
        {
            minVal= min(minVal,nums[i]);
        }
        return minVal;
        
    }
};