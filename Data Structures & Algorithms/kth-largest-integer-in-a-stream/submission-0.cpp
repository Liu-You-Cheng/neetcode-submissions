class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int> > pq;
    int K = 0;
    KthLargest(int k, vector<int>& nums) {
        this->K = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};
