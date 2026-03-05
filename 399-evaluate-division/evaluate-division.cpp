class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string,double>>> graph;
        unordered_map<string,double> weight;

        // Build graph
        for(int i = 0; i < equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];

            graph[a].push_back({b, 1.0 / values[i]});
            graph[b].push_back({a, values[i]});
        }

        vector<unordered_set<string>> groups;

        // BFS to compute relative weights
        for(auto &node : graph){
            if(weight.count(node.first)) continue;

            queue<string> q;
            unordered_set<string> comp;

            q.push(node.first);
            weight[node.first] = 1.0;
            comp.insert(node.first);

            while(!q.empty()){
                string curr = q.front();
                q.pop();

                for(auto &nbr : graph[curr]){
                    string next = nbr.first;
                    double val = nbr.second;

                    if(!weight.count(next)){
                        weight[next] = weight[curr] * val;
                        q.push(next);
                        comp.insert(next);
                    }
                }
            }

            groups.push_back(comp);
        }

        vector<double> result;

        // Process queries
        for(auto &q : queries){
            string a = q[0];
            string b = q[1];

            if(!weight.count(a) || !weight.count(b)){
                result.push_back(-1.0);
                continue;
            }

            bool found = false;

            for(auto &g : groups){
                if(g.count(a) && g.count(b)){
                    result.push_back(weight[a] / weight[b]);
                    found = true;
                    break;
                }
            }

            if(!found) result.push_back(-1.0);
        }

        return result;
    }
};