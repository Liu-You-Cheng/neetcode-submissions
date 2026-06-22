class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> c_table(26,0);
        for(int i = 0 ; i < s.size(); i++){
            int tmp = s[i] - 'a';
            c_table[tmp]++;
        }
        
        for(int i = 0; i < t.size(); i++){
            c_table[t[i] - 'a']--;
            if(c_table[t[i] - 'a'] < 0){
                return false;
            }
        }

        for(int i = 0 ; i < c_table.size(); i++){
            if(c_table[i] != 0) return false;
        }

        return true;
    }
};
