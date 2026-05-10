class Solution {
    bool can = false;
    int go(int i, int n, int target, vector<int>& nums, vector<int>& dp){
        if(i == n - 1) {
            can = true;
            return 0;
        }

        int &ret = dp[i];
        if(~ret) return ret;

        ret = -1e5;
        for(int j=i+1; j<n; j++){
            if(abs(nums[i] - nums[j]) <= target)
                ret = max(ret, go(j, n, target, nums, dp) + 1);
        }

        return ret;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);

        int ans = go(0, n, target, nums, dp);
        if(!can) return -1;
        else return ans;
    }
};