
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int k) {
        memset(dp,-1,201*201*2*sizeof(int));
        return (solve(zero, one, 1, k) + solve(zero, one, 0, k))%1000000007;
    }

    int dp[201][201][2];

    int solve(int zero, int one, bool endZero, int k) {
        if (zero == 0) return endZero == false && one > 0 && one <= k;
        else if (one == 0) return endZero == true && zero > 0 && zero <= k;

        int& res = dp[zero][one][endZero]; if(res>=0) return res;

        int r=0;
        if (endZero)
            for (int i = 1; i <= k && zero - i >= 0; ++i) r = (r+solve(zero - i, one, false, k))%1000000007;
        else
            for (int i = 1; i <= k && one - i >= 0; ++i) r = (r+solve(zero, one - i, true, k))%1000000007;

        res=r;
        return r;
    }
};