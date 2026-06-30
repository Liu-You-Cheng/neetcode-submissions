class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ans = stones[0];
        auto cmp = [](int a , int b){
            return a < b;
        };
        priority_queue<int,vector<int>,decltype(cmp)> max_hp;
        for(auto s : stones){
            max_hp.push(s);
        }
        
        // smashing
        while(max_hp.size() > 1){
            int biggest = max_hp.top();
            max_hp.pop();
            int sec_biggest = max_hp.top();
            max_hp.pop();
            
            if(biggest != sec_biggest){
                max_hp.push(biggest- sec_biggest);
            }
            if(max_hp.size() == 0){
                return 0;
            }
            ans = max_hp.top();
        }
        return ans;
    }
};
