class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, idx = 0, n = chars.size();

        while(i < n){
            char curr = chars[i];
            int count = 0;

            while(i < n && chars[i] == curr){
                count++;
                i++;
            }

            chars[idx++] = curr;

            if(count > 1){
                string cnt = to_string(count);
                for(char c: cnt){
                    chars[idx++] = c;
                }
            }
        }
        
        return idx;
    }
};