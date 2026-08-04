class LRUCache {
private:
    int capacity;
    // Key -> {Value, 該 Key 在 map 中被寫入/讀取的總次數}
    std::unordered_map<int, std::pair<int, int>> hmp;
    // Key -> 這次 push 時，該 Key 的期望訪問計數
    std::queue<std::pair<int, int>> q; 

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (hmp.find(key) == hmp.end()) return -1;
        
        hmp[key].second++; // 增加訪問計數（代表這是一個更新的狀態）
        q.push({key, hmp[key].second}); // 丟入 queue 尾端
        return hmp[key].first;
    }
    
    void put(int key, int value) {
        if (hmp.find(key) != hmp.end()) {
            hmp[key].first = value;
            hmp[key].second++;
            q.push({key, hmp[key].second});
            return;
        }
        
        // 容量滿了
        if (hmp.size() >= capacity) {
            // 核心邏輯：清除 queue 前端所有「過期」的紀錄
            while (!q.empty()) {
                auto [front_key, front_count] = q.front();
                q.pop();
                
                // 如果這個 key 在 map 裡還存在，且計數與 queue 紀錄的一致
                if (hmp.find(front_key) != hmp.end() && hmp[front_key].second == front_count) {
                    hmp.erase(front_key); // 這才是真正最久沒用且沒有更新過的資料
                    break;
                }
                // 如果不一致，代表它是舊資料，直接 ignore（剛剛 pop 掉了）
            }
        }
        
        hmp[key] = {value, 1};
        q.push({key, 1});
    }
};