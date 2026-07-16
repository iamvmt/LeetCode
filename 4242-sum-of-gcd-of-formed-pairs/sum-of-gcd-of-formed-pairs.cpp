class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        prefixGcd(nums);
        return Gcf(ans);
    }

private:
    int maxi = 0;
    vector<int> ans;
    vector<int> prefixGcd(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {

            maxi = max(maxi, nums[i]);
            int hcf = gcdOfNum(maxi, nums[i]);

            ans.push_back(hcf);
        }
        return ans;
    }
    long long Gcf(vector<int> ans) {
        long long result = 0;
        long long n = ans.size();
        vector<int> res;
        long long val = 0;
        long long low = 0;
        long long high = n - 1;
        sort(ans.begin(), ans.end());
        while (low < high) {
            val = gcdOfNum(ans[low], ans[high]);
            low++;
            high--;
            res.push_back(val);
        }
        for (int i = 0; i < res.size(); i++) {
            result += res[i];
        }

        return result;
    }

    int gcdOfNum(int a, int b) {
        if (b == 0)
            return a;

        return gcdOfNum(b, a % b);
    }
};