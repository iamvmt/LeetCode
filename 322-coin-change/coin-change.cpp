class Solution {
public:
    int dp[20][60000];
    int func(int i, int amount, vector<int> &nums) {
        if(amount==0) {
            return 0;
        }
        if(amount<0) {
            return 50000;
        }
        if(i==nums.size()) {
            return 50000;
        }
        if(dp[i][amount]!=-1) {
            return dp[i][amount];
        }
        int val = min(1+func(i,amount-nums[i],nums), func(i+1, amount, nums));
        dp[i][amount]=val;
        return val;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int val =  func(0, amount, coins);
        if(val==50000) {
            return -1;
        }
        return val;
    }
};