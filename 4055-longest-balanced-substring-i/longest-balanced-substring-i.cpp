class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;  
                int freq = mpp.begin()->second;
                bool flag = true;
                for (auto &it : mpp) {
                    if (it.second != freq) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};