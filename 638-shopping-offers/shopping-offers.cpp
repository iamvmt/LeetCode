class Solution {
public:
    unordered_map<string, int> memo;
    vector<int> price;
    vector<vector<int>> special;
    
    int shoppingOffers(vector<int>& p, vector<vector<int>>& s, vector<int>& n) {
        price = p;
        special = s;
        return solve(n);
    }
    
    string getKey(vector<int>& need) {
        string key;
        for (int x : need) key += to_string(x) + ",";
        return key;
    }
    
    int solve(vector<int> need) {
        string key = getKey(need);
        if (memo.count(key)) return memo[key];
        
        
        int res = 0;
        for (int i = 0; i < need.size(); ++i)
            res += price[i] * need[i];
        
        
        for (auto& offer : special) {
            vector<int> temp = need;
            bool valid = true;
            
            for (int i = 0; i < need.size(); ++i) {
                temp[i] -= offer[i];
                if (temp[i] < 0) {
                    valid = false;
                    break;
                }
            }
            
            if (valid)
                res = min(res, offer.back() + solve(temp));
        }
        
        return memo[key] = res;
    }
};