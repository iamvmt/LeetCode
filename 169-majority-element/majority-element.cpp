class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0;
        int element;

        for(int i = 0; i<n; i++){
            if(count1 == 0)
            {
                count1 = 1;
                element = nums[i];
            }
            else if(element == nums[i]) count1++;
            else count1--;
        }

        int count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(element == nums[i]) count2++;
        }

        if(count2 > n/2) return element;

        return -1;
    }
};