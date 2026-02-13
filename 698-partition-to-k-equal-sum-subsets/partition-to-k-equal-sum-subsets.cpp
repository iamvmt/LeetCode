class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int x : nums) total += x;
        if (total % k) return false;
        
        int target = total / k;
        sort(nums.rbegin(), nums.rend());
        vector<bool> used(nums.size(), false);
        
        return backtrack(nums, used, 0, k, 0, target);
    }
    
private:
    bool backtrack(vector<int>& arr, vector<bool>& used, int idx, int remaining, int sum, int goal) {
        if (remaining == 0) return true;
        
        if (sum == goal)
            return backtrack(arr, used, 0, remaining - 1, 0, goal);
        
        for (int i = idx; i < arr.size(); i++) {
            if (used[i] || sum + arr[i] > goal) continue;
            
            used[i] = true;
            if (backtrack(arr, used, i + 1, remaining, sum + arr[i], goal))
                return true;
            used[i] = false;
            
            
            if (sum == 0) return false;
        }
        
        return false;
    }
};