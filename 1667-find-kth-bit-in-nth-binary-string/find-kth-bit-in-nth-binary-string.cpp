class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        n--;
        while(n--) {
            string ss = s;
            reverse(ss.begin(), ss.end());
            for(auto &i : ss) i = i ^ '0' ^ '1';
            s = s + "1" + ss;
        }
        return s[k-1];
    }
};