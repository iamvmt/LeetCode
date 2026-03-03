class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i<haystack.size(); i++){
            int idx = i;

            int j = 0;
            while(haystack[i] == needle[j] && needle[j] != '\0'){
                i++;
                j++;
            }
            if(needle[j] == '\0'){
                return idx;
            }
            i = idx;
        }
        return -1;
    }
};