class Solution {
public:
    
    void add(map<int,int>& mp, map<int,int>& diff, int x) {
        if (mp[x] > 0) {
            mp[x]++;
            return;
        }

        auto it = mp.lower_bound(x);
        int prv = INT_MAX, nxt = INT_MAX;

        if (it != mp.begin()) {     
            prv = prev(it)->first;
        }
        if (next(it) != mp.end()) {
            nxt = next(it)->first;
        }

        // remove old gap
        if (prv != INT_MAX && nxt != INT_MAX) {
            int d = abs(nxt - prv);
            if (--diff[d] == 0) diff.erase(d);
        }

        if (prv != INT_MAX) diff[abs(x - prv)]++;
        if (nxt != INT_MAX) diff[abs(nxt - x)]++;

        mp[x]++;
    }

    void remove(map<int,int>& mp, map<int,int>& diff, int x) {
        mp[x]--;
        if (mp[x] > 0) 
        {
            return;
        }

        auto it = mp.find(x);
        int prv = INT_MAX, nxt = INT_MAX;

        if (it != mp.begin()) {
            prv = prev(it)->first;
        }
        auto it2 = next(it);
        if (it2 != mp.end()) {
            nxt = it2->first;
        }

        // remove gaps involving x
        if (prv != INT_MAX) {
            int d = abs(x - prv);
            if (--diff[d] == 0) diff.erase(d);
        }
        if (nxt != INT_MAX) {
            int d = abs(nxt - x);
            if (--diff[d] == 0) diff.erase(d);
        }

        // add merged gap
        if (prv != INT_MAX && nxt != INT_MAX) {
            diff[abs(nxt - prv)]++;
        }

        mp.erase(x);
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            map<int,int> mp;
            map<int,int> diff;

            // initial window
            for (int r = i; r < i + k; r++) {
                for (int c = 0; c < k; c++) {
                    add(mp, diff, grid[r][c]);
                }
            }
            ans[i][0] = diff.empty() ? 0 : diff.begin()->first;

            for (int j = 1; j <= n - k; j++) {

                // remove left column
                for (int r = i; r < i + k; r++) {
                    remove(mp, diff, grid[r][j - 1]);
                }

                // add right column
                for (int r = i; r < i + k; r++) {
                    add(mp, diff, grid[r][j + k - 1]);
                }
          
                ans[i][j] = diff.empty() ? 0 : diff.begin()->first;
            }
        }

        return ans;
    }
};