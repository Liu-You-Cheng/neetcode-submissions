class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int len = 1;

        for (int i = 0; i < s.size(); ++i) {

            // odd
            int count = 1;

            while (i - count >= 0 &&
                   i + count < s.size()) {

                if (s[i - count] == s[i + count]) {

                    int curLen = count * 2 + 1;

                    if (curLen > len) {
                        len = curLen;
                        start = i - count;
                    }

                    count++;

                } else {
                    break;
                }
            }

            // even
            count = 0;

            while (i - count >= 0 &&
                   i + count + 1 < s.size()) {

                if (s[i - count] == s[i + count + 1]) {

                    int curLen = count * 2 + 2;

                    if (curLen > len) {
                        len = curLen;
                        start = i - count;
                    }

                    count++;

                } else {
                    break;
                }
            }
        }

        return s.substr(start, len);
    }
};