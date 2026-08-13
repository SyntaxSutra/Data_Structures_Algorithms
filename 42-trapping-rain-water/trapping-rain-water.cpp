class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;

        int leftmax = 0;
        int rightmax = 0;
        int totalWater = 0;

        while(left < right)
        {
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);


            if(leftmax < rightmax)
            {
                totalWater += leftmax - height[left];
                left++;
            }
            else
            {
                totalWater += rightmax - height[right];
                right--;
            }
        } 
        return totalWater;
    }
};