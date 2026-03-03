class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l = n-1;
        for(int i = 0; i<n/2; i++){
            int temp = s[i];
            s[i] = s[l];
            s[l] = temp;
            l--;
        }
    }
};