class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1] + 1)
                break;
            
            sum += nums[i];
        }

        set<int> st;
        for (int num: nums) {
            st.insert(num);
        }

        int x = sum;
        while (st.contains(x)) {
            x++;
        }

        return x;
    }
};