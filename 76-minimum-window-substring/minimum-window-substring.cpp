class Solution {
public:
    string minWindow(string s, string t) {

        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> need;
        unordered_map<char, int> window;

     
        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

        
            window[s[right]]++;

    
            if (need.count(s[right]) &&
                window[s[right]] <= need[s[right]]) {
                count++;
            }

        
            while (count == t.size()) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

           
                if (need.count(s[left]) &&
                    window[s[left]] <= need[s[left]]) {
                    count--;
                }

                window[s[left]]--;
                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};