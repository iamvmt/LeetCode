class Solution {
    static const int N = 2e4 + 2;

    int ma, mi;
    int f[N];

    void update(int x) {
        for (; x <= ma - mi + 1; x += x & -x) {
            ++f[x];
        }
    }
    int get(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res += f[x];
        }
        return res;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        mi = *min_element(nums.begin(), nums.end());
        ma = *max_element(nums.begin(), nums.end());

        vector <int> res((int) nums.size(), 0);

        for (int i = (int) nums.size()-1; i >= 0; --i) {
            res[i] = get(nums[i] - mi + 1);
            update(nums[i] - mi + 2);
        }

        return res;
    }
};