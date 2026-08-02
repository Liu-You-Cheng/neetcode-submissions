class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        auto cmp = [](pair<int,int> a, pair<int,int> b){
            return (a.first* a.first + a.second* a.second) < (b.first* b.first + b.second* b.second);
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq;

        for(int i = 0; i < points.size(); i++){
            pq.push(pair(points[i][0],points[i][1]));
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            vector<int> tmp = {pq.top().first, pq.top().second};
            ans.push_back(tmp);
            pq.pop();
        }
        
        return ans;
    }
};
