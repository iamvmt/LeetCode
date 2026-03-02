class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            long long targetCount = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == target)
                    targetCount++;

                if (2LL * targetCount > (long long)(j - i + 1))
                    result++;
            }
        }

        return result;
    }
};