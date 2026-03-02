class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size();
        array<int, 200> zero;
        for (int i = 0; auto& row: grid) {
            auto it = find(rbegin(row), rend(row), 1);
            zero[i++] = it - rbegin(row);
        }
        for (int i = 0; i < n; ++i) {
            int j = find_if(begin(zero) + i, begin(zero) + n, [&] (int a) { return a >= n - i - 1; }) - begin(zero);
            if (j == n)
                return -1;
            int tmp = zero[j];
            copy(begin(zero) + i, begin(zero) + j, begin(zero) + i + 1);
            zero[i] = tmp;
            ans += j - i;
        }
        return ans;
    }
};