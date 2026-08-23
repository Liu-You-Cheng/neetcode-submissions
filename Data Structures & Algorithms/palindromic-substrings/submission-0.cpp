class Solution {
   public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            bool odd_end = false;
            bool even_end = false;
            int count = 0;
            while (!odd_end || !even_end) {
                if (!odd_end) {
                    odd(s, ans, i, count, odd_end);
                }
                if (!even_end) {
                    even(s, ans, i, count, even_end);
                }
                count++;
            }
        }
        return ans;
    }

    void odd(const string& str, int& ans, int start, int count, bool& stop) {
        if (start < count || str.size() <= start + count) {
            stop = true;
            return;
        }
        if (str[start - count] != str[start + count]) {
            stop = true;
            return;
        } else {
            ans++;
        }
    }
    void even(const string& str, int& ans, int start, int count, bool& stop) {
        if (start < count || str.size() <= start + 1 + count) {
            stop = true;
            return;
        }
        if (str[start - count] != str[start + 1 + count]) {
            stop = true;
            return;
        } else {
            ans++;
        }
    }
};
