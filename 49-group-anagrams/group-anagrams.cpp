class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> str(n);

        for(int i = 0; i < n; i++){
            str[i] = strs[i]; //VMT
            sort(str[i].begin(), str[i].end());
        }

        vector<vector<string>> res;

        map<string, bool> mp;

        for(int i = 0; i < n; i++){
            if(!mp[str[i]]){
                mp[str[i]] = true;
                vector<string> st;
                st.push_back(strs[i]);

                for(int j = i+1; j < n; j++){
                    if(str[i] == str[j]){
                        st.push_back(strs[j]);
                    }
                }

                res.push_back(st);
            }
        }

        return res;
    }
};