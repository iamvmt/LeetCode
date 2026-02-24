class Solution {
public:
int INF = 1e6;
int n;
vector<vector<vector<vector<int>>>> dp;

int rec(int level, int buy, int sell, vector<int> &prices, int k)
{
    if(level >= n)
    {
        if(sell == 0) return -INF;
        return 0;
    }

    if(dp[level][buy][sell][k] != -1) 
    return dp[level][buy][sell][k];

    int ans = 0;
        if(buy == 0)
        {
             if(k > 0)
                ans = max(ans, rec(level + 1, 1, 0, prices, k-1) + (-prices[level]) );
        }
        else
        {
             ans = max(ans, rec(level+1, 0, 1, prices, k) + (prices[level]));
        }

        ans = max(ans, rec(level+1, buy, sell, prices, k));

       
        dp[level][buy][sell][k] = ans;
        return ans;
    }


    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.clear();

        dp.resize(n , vector<vector<vector<int>>> ( 2, vector<vector<int>> (2, vector<int> (3, -1))));
        
        return rec(0, 0, 0, prices, 2);
    }
};