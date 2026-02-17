class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int n , vector<int>& res){
        if(target == 0){
            ans.push_back(res);
        }

        for (int i = n; i < candidates.size(); i++) {
            if (i > n && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            res.push_back(candidates[i]);
            solve( candidates, target - candidates[i],i + 1, res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> res;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target,0, res);
        return ans;
    }
};