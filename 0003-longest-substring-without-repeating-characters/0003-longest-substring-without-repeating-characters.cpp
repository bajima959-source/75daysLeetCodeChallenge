class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(256, -1); // stores last seen index
        int maxLength = 0;
        int start = 0; // left pointer of window

        for (int i = 0; i < s.length(); i++) {
            if (index[s[i]] >= start) {
                start = index[s[i]] + 1; // move start forward
            }
            index[s[i]] = i; // update last seen index
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};