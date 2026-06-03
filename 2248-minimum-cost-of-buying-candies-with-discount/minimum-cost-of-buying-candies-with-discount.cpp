class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int money = 0;
        for(int i=0; i<cost.size(); i++){
            if((i+1)%3 == 0) continue;
            money += cost[i];
        }

        return money;
    }
};