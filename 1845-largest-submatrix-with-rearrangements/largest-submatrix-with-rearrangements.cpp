class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n= matrix.size(), m= matrix[0].size();
        vector<vector<int>> mat(n, vector<int>(m, 0));

        for(int i=0; i<m; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(matrix[j][i]==1) cnt++;
                else cnt=0;
                mat[j][i]= cnt;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            sort(mat[i].rbegin(), mat[i].rend());
            for(int j=0; j<m; j++){
                if((j+1)*mat[i][j] > ans) ans= (j+1)*mat[i][j];
            }
        }
        return ans;
    }
};