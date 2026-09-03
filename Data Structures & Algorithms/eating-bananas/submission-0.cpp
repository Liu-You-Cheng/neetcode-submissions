class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        int k;
        for (const auto& p : piles) {
            if (p > r) {
                r = p;
            }
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int sum = 0;
            bool able = true;
            for (const auto& p : piles) {
                sum += (p % mid) == 0 ? (p / mid) : (p / mid) + 1;
                if (sum > h) {
                    able = false;
                    break;
                }
            }

            if (able) {
                k = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return k;
    }
};
