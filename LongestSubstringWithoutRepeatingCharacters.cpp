class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int dict[256];
        memset(dict, -1, sizeof dict);
        int maxLen = 0, start = -1;
        for(int i = 0; i != s.length(); i++) 
        {
            if(dict[s[i]] > start) // if last occurance is greater than start of current window, this indicates that a letter has been repeated in the current substring, we move the start of substring to the repeated index and start the search again
            {
                start = dict[s[i]];
            }
            dict[s[i]] = i; // track the last occurance of that character
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};