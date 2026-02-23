class Solution {
public:
    bool hasAllCodes(string s, int k) {
         if(k > s.length()) return false;

        set<deque<char>> st;
        deque<char> dq;

        for(int i = 0 ; i < k ; i++) 
            dq.push_back(s[i]);
        int j = k , n = s.length();
        while(j < n) { 
            st.insert(dq);
           
            dq.pop_front();
            dq.push_back(s[j]);
            j++;
        }
        st.insert(dq);
        int cnt = pow(2,k);
        return (int) st.size() == cnt;
    }
};