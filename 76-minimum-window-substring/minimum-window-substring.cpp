#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);
        for (char ch : t) {
            need[ch]++;
        }

        int required = 0;
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                required++;
            }
        }

        int formed = 0;
        int left = 0;

        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];

            window[ch]++;
            if (need[ch] > 0 && window[ch] == need[ch]) {
                formed++;
            }
            while (formed == required) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }
        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};