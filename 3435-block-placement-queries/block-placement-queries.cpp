class Solution {
public:
    const int N = 5e4  + 10, inf = 1e8;

    int tree_size;
    vector<int> tree;

    void upd(int li, int ri, int ni, int idx, int val){
        if(ri - li == 1){
            tree[ni] = val;
            return;
        }

        int m = (li + ri) >> 1;

        if(idx < m)
           upd(li, m, ni*2 + 1, idx, val);
        else
           upd(m, ri, ni * 2+2, idx, val);

           tree[ni] = max(tree[ni*2 + 1], tree[ni*2+2]);


    }

    int query(int li, int  ri, int ni, int l, int r){
        if(l <= li && r>= ri)
           return tree[ni];

        if(li >= r || ri <= l)
           return -inf;

        int m = (li + ri)>> 1;

        return max(query(li, m, ni*2+1, l, r), query(m, ri, ni*2+2, l, r));
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        tree_size = 1;

        while(tree_size < N)
              tree_size <<= 1;

        tree.assign(tree_size << 1, -inf);
        upd(0, tree_size, 0, N - 1, N -1);

        set<int> st;
        st.insert(0), st.insert(N-1);

        vector<bool> res;

        for(auto& queryx : queries){
            if(queryx[0] == 1){
                int x = queryx[1];

                auto it = st.upper_bound(x);
                int nxt = *it, prv = *prev(it);

                upd(0, tree_size, 0, x, x-prv);
                upd(0, tree_size, 0, nxt, nxt - x);

                st.insert(x);
            }

            else {
                int x = queryx[1], sz=queryx[2];

                auto it = st.upper_bound(x);
                int prv = *prev(it);

                int mx = query(0, tree_size, 0, 0, x+1);
                res.push_back(max(mx, x - prv) >= sz);
            }
        }

        return res;
    }
};