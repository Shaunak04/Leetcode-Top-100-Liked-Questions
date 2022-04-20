class Solution
{
public:
    void extendPalindrome(string s, int left, int right, int &start, int &len)
    {
        // start from a center point and expand the palindrome in both directions
        while(left>=0 && right<s.length() && s[left]==s[right]) // check for palindrome with 2 pointers
        {
            left--; // move left to left
            right++;// move right outwards to right
        }
        int new_len = right-left-1;
        if(new_len > len) // longer palindrome found after extending
        {
            start = left + 1;
            len = new_len;
        }
    }
    string longestPalindrome(string s)
    {
        int n = s.length();
        int start = 0, len = 1;
        if(n<2) // no palindrome exists
        {
            return s;
        }
        for(int i=0; i<n-1; i++)
        {
            // we choose 2 points left and right in the middle and move outwards, expanding palindrome to find a longer one
            extendPalindrome(s, i, i, start, len); // odd length palindrome
            extendPalindrome(s, i, i+1, start, len); // even length palindrome
        }
        return s.substr(start, len);
    }
};