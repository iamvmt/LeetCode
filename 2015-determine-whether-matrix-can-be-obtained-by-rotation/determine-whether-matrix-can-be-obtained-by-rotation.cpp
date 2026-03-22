class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int rot = 0;
        while (rot < 4) {
            vector<vector<int>> mataux(mat.size(), vector<int>(mat[0].size()));
            for (int i = 0; i < mataux.size(); ++i) {
                for (int j = 0; j < mataux[i].size(); ++j) {
                    mataux[i][j] = mat[mat[i].size() - 1 - j][i];
                }
            }
            if (mataux == target) {
                return true;
            }
            mat = mataux;
            ++rot;
        }
        return false;
    }
};