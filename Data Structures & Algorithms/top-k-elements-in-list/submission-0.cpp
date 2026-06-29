class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                map[nums[i]]++;
            } else {
                map[nums[i]] = 1;
            }
        }

        // create heap
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        for (const auto& pair : map) {
            minHeap.push(pair);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return ans;
    }
};
