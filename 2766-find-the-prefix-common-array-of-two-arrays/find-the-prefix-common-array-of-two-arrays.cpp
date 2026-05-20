class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> mp(51,0);
        int n = A.size();
        int count = 0;
        vector<int> ans;
        for(int i =0;i<n;i++){
            mp[B[i]]++;
            mp[A[i]]++;
            if(mp[A[i]]>1){
                count++;
            }
            if(mp[B[i]]>1){
                count++;
            }
            if(A[i]==B[i]){
                count--;
            }
            ans.push_back(count);
        }
        return ans;
    }
};