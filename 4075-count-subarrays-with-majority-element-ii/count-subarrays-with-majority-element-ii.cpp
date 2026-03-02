#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

namespace __gnu_pbds{
          typedef tree<long long,
                       null_type,
                       less_equal<long long>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> pref(n+1,0);
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + ( (nums[i-1]==target) ? 1 : -1);
        }
        long long ans = 0;

        ordered_set os;

        for(auto &s : pref){
            os.insert(s);
            ans += os.order_of_key(s);
        }
        return ans;
    }
};