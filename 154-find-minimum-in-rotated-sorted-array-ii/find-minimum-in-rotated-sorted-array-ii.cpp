class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        
        while (i < j) {
            int m = i + (j - i) / 2;
            

            //Adding comments for understanding later xDDDDDD
            // Minimum in left half including mid
            if (nums[m] < nums[j]) j = m;
            // Minimum in right half excluding mid
            else if (nums[m] > nums[j]) i = m + 1;
            // Handle duplicates
            else j--;
        }
        
        return nums[i];
    }
};