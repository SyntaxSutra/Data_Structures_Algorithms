class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        if (n <= k) 
        return s;

        string next = "";
        for (int i = 0; i <n ; i += k) 
        {
            int sum = 0;
            for (int j = i; j < n && j < i + k; j++)
                sum += s[j] - '0';
            next += to_string(sum);
        }

        return digitSum(next, k);
    }
};