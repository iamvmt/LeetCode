class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adj(n);
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> leaves;
        for(int i=0;i<n;i++){
            if(adj[i].size() == 1){
                leaves.push_back(i);
            }
        }
        
        int remaining = n;
        while(remaining > 2){
            remaining -= leaves.size();
            vector<int> newleaves;
            for(int leaf : leaves){
                int neighbour = adj[leaf][0];
                adj[neighbour].erase(find(adj[neighbour].begin(),adj[neighbour].end(),leaf));
                if(adj[neighbour].size() == 1) newleaves.push_back(neighbour);
            }
            leaves = newleaves;
        }

        return leaves;
    }
};