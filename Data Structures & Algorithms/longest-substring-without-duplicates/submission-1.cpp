class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        int ans = 1;

        for(int i = 0 ; i < s.size(); i++){
            unordered_map<char,int> mp;
            bool dup = false;
            int tmp = i;
            int count = 0;
            while(!dup && tmp < s.size()){
                if(mp.find(s[tmp]) == mp.end()){
                    mp[s[tmp]] = tmp;
                    tmp++;
                    count++;
                }else{
                    dup = true;
                    ans = max(ans,count);
                    i = mp[s[tmp]];
                }
            }
            if(tmp == s.size() && !dup)return max(ans,count);
        }
        return ans;
    }
};
