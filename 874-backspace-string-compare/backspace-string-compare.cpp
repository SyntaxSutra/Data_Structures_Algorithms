class Solution {
private:
    string makeString(string s)
    {
        string result = "";

        for(char c : s)
        {
            if(c == '#')
            {
                // Backspace: remove last character
                if(!result.empty())
                {
                    result.pop_back();
                }
            }
            else
            {
                // Normal character: add it
                result.push_back(c);
            }
        }

        return result;
    }

public:

    bool backspaceCompare(string s, string t)
    {
        return makeString(s) == makeString(t);
    }
};