struct node {
    int mn = 0;
    int mx = 0;
    int base = 0;
    node(){} 

    bool balance() { return (base + mn <= 0) && (base + mx >= 0); }

    void apply()
    {
        mx += base;
        mn += base;
        base = 0;
    }

    int getmax() { return mx + base; }
    int getmin() { return mn + base; }
};

struct tree {
    vector<node> arr;
    int n;
    void init(int n1) {
        n = n1; 
        arr = vector<node>(n * 4 + 2);
    }

    void apply(int l, int r, int cur, int carry)
    {
        auto& nd = arr[cur];
        nd.base += carry;
    }
    
    int search(int l, int r, int cur)
    {
        auto& nd = arr[cur];
        if (!nd.balance()) return INT_MAX;
        if (l == r)  return l;
        int m = (l + r) / 2;
        int carry = nd.base;
        nd.apply();
        apply(l, m, cur * 2, carry);
        apply(m + 1, r, cur * 2 + 1, carry);
        int ln = search(l, m, cur * 2);
        if (ln != INT_MAX) return ln;
        int rn = search(m + 1, r, cur * 2 + 1);
        return rn;
    }
    
    node& update(int l, int r, int cur, int x, int y, int delta) {
        if (y < l || x > r)  return arr[cur];
        if ( x <= l && r <= y)  {
            arr[cur].base += delta;
            return arr[cur];
        }
        else 
        {
            auto& nd = arr[cur];
            int m = (l + r) / 2;
            apply(l, m, cur * 2, nd.base);
            apply(m + 1, r, cur * 2 + 1, nd.base);
            auto& ln  = update(l, m, cur * 2, x, y, delta);
            auto& rn = update(m + 1, r, cur * 2 + 1, x, y, delta);
            nd.mx = max(ln.getmax(), rn.getmax());
            nd.mn = min(ln.getmin(), rn.getmin());
            nd.base = 0;
        }
        return arr[cur];
    }
};

class Solution {
public:
    int n;
    int longestBalanced(vector<int>& nums) {
       n = nums.size();
       unordered_map<int, int> pos;
       int ans = 0;
       tree t;
       t.init(n);
       for (int i = 0; i < n; i++)
       {
            int v = nums[i];
            int delta = ((v % 2) == 0) ? 1 : -1;
            int r = i;
            int l = pos.count(v) ? pos[v] + 1 : 0;
            t.update(0, n - 1, 1, l, r, delta);
            int left = t.search(0, n - 1, 1);
            if (left < r) ans = max(ans, r - left + 1);
            pos[v] = i;
       }
       return ans;
    }
};