class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int duplicate = -1, missing = -1;
        int n = nums.size();

        for (int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                duplicate = nums[i];
            }
            else if (nums[i] > nums[i-1]+1){
                missing = nums[i-1] + 1;
            }
        }
       if (missing == -1) {
            if (nums[0] != 1)
                missing = 1;        
            else
                missing = n;        
        }
       return {duplicate, missing};
    }
};