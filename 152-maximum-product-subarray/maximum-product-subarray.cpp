class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curr = 1;
        int maxp = INT_MIN;

        for(int i = 0; i < n; i++) {
            curr *= nums[i];
            maxp = max(maxp, curr);
            if(curr == 0) curr = 1;
        }

        curr = 1; 

        for(int i = n - 1; i >= 0; i--) {
            curr *= nums[i];
            maxp = max(maxp, curr);
            if(curr == 0) curr = 1;
        }

        return maxp;
    }
};