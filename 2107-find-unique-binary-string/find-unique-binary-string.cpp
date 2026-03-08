class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result="";
        for(int i=0;i<nums.size();i++){
            if(nums[i][i]=='1') result+='0';
            else result+='1';
        }
        return result;
    }
};