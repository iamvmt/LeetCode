class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {

        int n = a.size();
        int MAX_diff = INT_MAX;
        int bestSum = 0;   

        sort(a.begin(), a.end());

        for (int i = 0; i < n - 2; i++) {

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int s = a[i] + a[l] + a[r];
                int diff = abs(s - target);

                if (diff < MAX_diff) {
                    MAX_diff = diff;
                    bestSum = s;   
                }

                if (s == target) {
                    return s;
                } 
                else if (s < target) {
                    l++;
                } 
                else {
                    r--;
                }
            }
        }
        return bestSum;   
    }
};