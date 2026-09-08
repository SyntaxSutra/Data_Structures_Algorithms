#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;

        // Step 1: Sort the array — enables two pointers + easy duplicate skipping
        sort(nums.begin(), nums.end());

        // Step 2: Fix first element with index i
        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate values for i (only after first iteration)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Early termination: smallest possible 4-sum exceeds target
            // Cast to long long before arithmetic to avoid overflow!
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;

            // Pruning: largest possible 4-sum is less than target → skip this i
            if ((long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;

            // Step 3: Fix second element with index j
            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate values for j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Early termination for j level
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;

                // Pruning for j level
                if ((long long)nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;

                // Step 4: Two-pointer search for the remaining pair
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // MUST use long long — values up to 10^9, sum up to 4*10^9
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        // Valid quadruplet found!
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for left pointer
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // Skip duplicates for right pointer
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        // Move both pointers inward
                        left++;
                        right--;

                    } else if (sum < target) {
                        left++;   // Need a bigger value

                    } else {
                        right--;  // Need a smaller value
                    }
                }
            }
        }

        return result;
    }
};