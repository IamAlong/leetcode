class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1 || s.length() == 0) {
            return s.length();
        }
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s.substr(i, j - i).find(s[j]) != s.npos) {
                    if (j - i > max) {
                        max = j - i;
                    }
                    i = s.substr(i, j - i).find(s[j]) + i;
                    break;
                } else if (j ==  s.length() - 1) {
                    if (j  - i + 1  >  max) {
                        return j - i + 1;
                    }
                }
            }
        }
        return max;
    }
};
