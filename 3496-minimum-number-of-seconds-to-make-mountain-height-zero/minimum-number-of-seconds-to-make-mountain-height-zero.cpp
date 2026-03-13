class Solution {
    using ll = long long;

    int sum(int n) {
        return n * (n + 1) / 2;
    }

    ll findN(ll x, ll mid) {
        long double val = (-1.0 + sqrt(1.0 + 8.0 * mid / x)) / 2.0;
        return floor(val);
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        auto check = [&] (ll mid) -> bool {
            ll tot = 0;

            for(int i = 0; i < n; i++) {
                int x = workerTimes[i];

                ll shaved = findN(x, mid);
                tot += shaved;
            }

            return tot >= mountainHeight;
        };
        

        ll lo = 1;
        ll hi = 1e18;
        ll res = hi;

        while(lo <= hi) {
            ll mid = lo + (hi - lo) / 2;

            if(check(mid)) {
                res = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        return res;
    }
};