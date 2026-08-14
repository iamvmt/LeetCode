class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int left = 0;
        int maxLength = 0;
        unordered_map<char, int>mp;
        for(int right = 0; right<n; right++){
            mp[s[right]]++;
            while(mp[s[right]] > 2){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};