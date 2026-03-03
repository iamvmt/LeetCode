class Solution {
public:
    
    vector<int> getLargestMerge(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        int i=0, j=0;
        while(i<n1 && j<n2){
            if(nums1[i] > nums2[j])
                ans.push_back(nums1[i++]);
            else if(nums1[i] < nums2[j])
                ans.push_back(nums2[j++]);
            else{
                int ii=i, jj=j;
                while(ii<n1 && jj<n2 && nums1[ii] == nums2[jj]){
                    ii++;
                    jj++;
                }

                if(ii==n1)
                    ans.push_back(nums2[j++]);
                else if(jj==n2)
                    ans.push_back(nums1[i++]);
                else if(nums1[ii] > nums2[jj])
                    ans.push_back(nums1[i++]);
                else if(nums1[ii] < nums2[jj])
                    ans.push_back(nums2[j++]);
            }
        }

        while(i<n1)
            ans.push_back(nums1[i++]);
        while(j<n2)
            ans.push_back(nums2[j++]);
        
        return ans;
    }

    
    vector<int> getLargestLexicographicalSubsequence(vector<int>& nums, int eliminationsRequired){
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            while(ans.size() && ans.back() < nums[i] && eliminationsRequired>0){
                ans.pop_back();
                eliminationsRequired--;
            }

            ans.push_back(nums[i]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        
        if(k == n1+n2)
            return getLargestMerge(nums1, nums2);

        
        for (int ki = max(0, k - n2); ki <= min(k, n1); ki++){
           
            int k1 = ki;
            int k2 = k-k1;

            vector<int> lls1 = getLargestLexicographicalSubsequence(nums1, n1-k1);
            vector<int> lls2 = getLargestLexicographicalSubsequence(nums2, n2-k2);

            vector<int> tempAns = getLargestMerge(lls1, lls2);

           
            while(tempAns.size() > k){
                tempAns.pop_back();
            }

            ans = max(ans, tempAns);
        }

        return ans;
    }
};