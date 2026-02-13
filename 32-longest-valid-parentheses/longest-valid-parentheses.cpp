class Solution {
public:
    int longestValidParentheses(string &s) {
        int len = s.length();
        vector<bool> valid(len, false);
        stack<int> stk;
        
        
        for (int idx = 0; idx < len; idx++) {
            if (s[idx] == '(' ) {
                stk.push(idx);
            } else if (!stk.empty()) {
                int opener = stk.top();
                stk.pop();
                valid[idx] = valid[opener] = true;
            }
        }
        
       
        int maxLen = 0, currLen = 0;
        for (int idx = 0; idx < len; idx++) {
            if (valid[idx]) {
                currLen++;
                maxLen = max(maxLen, currLen);
            } else {
                currLen = 0;
            }
        }
        
        return maxLen;
    }
};