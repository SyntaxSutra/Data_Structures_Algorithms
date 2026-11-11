class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        result.reserve(n-k+1);

        int consecutive_count = 1;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                if(nums[i] == nums[i-1]+1)
                {
                    consecutive_count++;
                }
                else
                {
                    consecutive_count=1;
                }
            }
            if(i>=k-1)
            {
                if(consecutive_count>=k)
                {
                    result.push_back(nums[i]);
                }
                else
                {
                    result.push_back(-1);
                }
            }
        }
        return result;
        
    }
};