class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n){
            int remainder = n%2;
            int newValue = n/2;
            if((remainder + newValue) % 2 == 0)return false;
            n = n/2;
        }
        return true;
    }
};