class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;
        
      
        maxLen = max(maxLen, findLongestRun(s));
        
       
        maxLen = max(maxLen, findBalancedPair(s, 'a', 'b'));
        maxLen = max(maxLen, findBalancedPair(s, 'a', 'c'));
        maxLen = max(maxLen, findBalancedPair(s, 'b', 'c'));
        
       
        maxLen = max(maxLen, findBalancedTriplet(s));
        
        return maxLen;
    }
    
private:
    int findLongestRun(const string& str) {
        if (str.empty()) return 0;
        
        int maxRun = 1, currentRun = 1;
        
        for (size_t i = 1; i < str.length(); i++) {
            currentRun = (str[i] == str[i-1]) ? currentRun + 1 : 1;
            maxRun = max(maxRun, currentRun);
        }
        
        return maxRun;
    }
    
    int findBalancedPair(const string& str, char first, char second) {
        unordered_map<int, int> firstSeen;
        firstSeen[0] = -1;
        
        int balance = 0, result = 0;
        
        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] != first && str[i] != second) {
                firstSeen.clear();
                firstSeen[0] = i;
                balance = 0;
                continue;
            }
            
            balance += (str[i] == first) ? 1 : -1;
            
            if (firstSeen.count(balance)) {
                result = max(result, (int)i - firstSeen[balance]);
            } else {
                firstSeen[balance] = i;
            }
        }
        
        return result;
    }
    
    int findBalancedTriplet(const string& str) {
        array<int, 3> freq = {0, 0, 0};
        unordered_map<string, int> stateMap;
        stateMap["0,0"] = -1;
        
        int result = 0;
        
        for (size_t i = 0; i < str.length(); i++) {
            freq[str[i] - 'a']++;
            
            string state = to_string(freq[1] - freq[0]) + "," + 
                          to_string(freq[2] - freq[0]);
            
            if (stateMap.count(state)) {
                result = max(result, (int)i - stateMap[state]);
            } else {
                stateMap[state] = i;
            }
        }
        
        return result;
    }
};