class Solution {
   public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int left = 0, max_count = 0, max_len = 0;

        for (int right = 0; right < s.size(); ++right) {
            max_count = max(max_count, ++counts[s[right] - 'A']);

            if ((right - left + 1) - max_count > k) { //overflow
                counts[s[left] - 'A']--; // reduce
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
