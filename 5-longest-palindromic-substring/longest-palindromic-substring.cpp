class Solution {
private:
    bool isPalindrome(const string &s , int l , int r)
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
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxLen = 1;
        for(int i = 0 ;i<n ; i++)
        {
            for(int j=i+1 ; j<n ;j++)
            {
                if(isPalindrome(s,i,j))
                {
                    int length = j-i+1;
                    if(length>maxLen)
                    {
                        maxLen = length;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};