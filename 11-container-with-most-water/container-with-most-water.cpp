class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left =0;
        int right = n-1;
        int maxWater = 0;

        while(left < right)
        {
            int current = min(height[left],height[right]) * (right - left);
            maxWater = max(maxWater , current);

            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxWater;

        
    }
};