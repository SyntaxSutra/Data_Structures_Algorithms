class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return 0;

        sort(nums.begin(),nums.end());

        int currentConsecutive = 1;
        int longestConsecutive = 0;

        for(int i=1;i<n;i++)
        {
            if(nums[i]  != nums[i-1])
            {
                if(nums[i] == nums[i-1]+1)
                {
                    currentConsecutive++;
                }
                else
                {
                    longestConsecutive = max(longestConsecutive,currentConsecutive);

                    currentConsecutive = 1;
                }
            }

        }
        return max(longestConsecutive,currentConsecutive);
        
    }
};