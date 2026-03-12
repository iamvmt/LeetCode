class DSU{
public:
    vector<int> parent, size;
    int components;

    DSU(int n){
        components = n;

        for(int i = 0; i < n; i++){
            size.push_back(1);
            parent.push_back(i);
        }
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulpu = findParent(u);
        int ulpv = findParent(v);

        if(ulpu == ulpv) return;

        components--;

        if(size[ulpu] < size[ulpv]) {
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else{
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
};

class Solution {
private:
    bool canPossible(int mid, vector<vector<int>> &edges, int &n, int &k)
    {
        DSU dsu(n);

       
        for(vector<int> &edge : edges){
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];

            if(must == 1){
                if(mid > s) return false;
                if(dsu.findParent(u) == dsu.findParent(v)) return false;

                dsu.unionBySize(u, v);
            }
        }

       
        for(vector<int> &edge : edges){
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];

            if(must == 0 && mid <= s){
                dsu.unionBySize(u, v);
            }
        }
 
      
        int upgrades = 0;

        for(vector<int> &edge : edges){
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];

            if(must == 0 && mid > s && 2*s >= mid){
                if(dsu.findParent(u) != dsu.findParent(v)){
                    dsu.unionBySize(u, v);
                    upgrades++;

                    if(upgrades > k) return false;
                }
            }
        }

        return dsu.components == 1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        DSU dsu(n);

        int low = 1, high = 0;

        for(vector<int> &edge : edges){
            int u = edge[0], v = edge[1], s = edge[2], must = edge[3];

           
            high = max(high, 2*s);


            if(must == 1){
                
                if(dsu.findParent(u) == dsu.findParent(v)) return -1;

                dsu.unionBySize(u, v);
            }
        }

        int res = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canPossible(mid, edges, n, k)){
                res = mid;
                low = mid + 1; 
            }
            else{
                high = mid - 1;
            }
        }


        return res;
    }
};