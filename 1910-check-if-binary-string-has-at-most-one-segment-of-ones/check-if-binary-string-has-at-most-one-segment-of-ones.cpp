class Solution {
public:
    bool checkOnesSegment(string s) {
        int lastOne = 0;
        int n = s.length();

        for(int i = 1; i<n; i++){
            if(s[i] == '1'){
                if(lastOne != i - 1)
                return false;

                else 
                lastOne = i;
            }
        }

        return true;
    }
};