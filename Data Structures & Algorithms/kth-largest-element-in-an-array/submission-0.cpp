class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](int a, int b){
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
