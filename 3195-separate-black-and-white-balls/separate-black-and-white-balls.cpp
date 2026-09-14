class Solution {
public:
    long long minimumSteps(string s) {

        long long swaps = 0;
        int blackCount = 0;

        for (char c : s) {

            if (c == '1') {
                blackCount++;
            }
            else {
                swaps += blackCount;
            }
        }

        return swaps;
    }
};