class PrefixTree {
private:
    struct TrieNode{
        TrieNode* children[26] = {nullptr};
        bool is_end = false;
    };

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            int index = c - 'a';
            if(curr->children[index] == nullptr){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false; // 沒路了，代表單字不存在
            }
            curr = curr->children[index];
        }
        return curr->is_end; // 必須是真的結尾才算找到
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false; // 沒路了，前綴不存在
            }
            curr = curr->children[index];
        }
        return true; // 只要能順利走完前綴的每個字母，就代表存在
    }
};
