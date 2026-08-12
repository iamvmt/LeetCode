class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        

        unordered_map<int, int> freq;

        int left = 0;
        int res = 0;

        for (int right = 0; right < nums.size(); right++){
            freq[nums[right]]++;

            while (freq[nums[right]] > k){
                freq[nums[left]]--;

                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }

                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};