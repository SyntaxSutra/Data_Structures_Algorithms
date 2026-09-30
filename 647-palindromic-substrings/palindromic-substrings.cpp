class Solution {
private:
    bool isPalindrome(const string&s , int l , int r)
    {
        while(l<r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }


public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0 ;i<n;i++)
        {
            for(int j= i;j<n;j++)
            {
                if(isPalindrome(s,i,j))
                {

                    count++;
                }

            }
           
        }
        return count;
        
    }
};