class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        
        int n =  num.size();
        int i = n-1;
        while(i>=0 || k>0)
        {
            if(i>=0)
            {
                k = k + num[i];
                i--;
            }
            result.push_back(k%10);
            k=k/10;
        }
        reverse(result.begin() , result.end());
        return result;
        
    }
};