class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i<=n-k ;i++)
        {
            unordered_map<int,int>freq;
            for(int j=i;j<i+k;j++)
            {
                freq[nums[j]]++;
            }
            vector<pair<int,int>>candidates;
            for(auto it : freq)
            {
                candidates.push_back({it.second,it.first});

            }
            sort(candidates.begin(),candidates.end(),greater<pair<int,int>>());
            int sum = 0;
            for(int j = 0 ; j<min(x,(int)candidates.size());j++)
            {
                sum += candidates[j].first * candidates[j].second;
            }
            ans.push_back(sum);
        }
        return ans;

    }
};