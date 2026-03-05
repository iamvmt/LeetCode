class Solution {
public:
    int minOperations(string s) {
          int n = s.size();
           int min1=0, min2=0;
            
             for(int i=0; i<n; i++){
                   if(i%2 ==0){
                       if(s[i] != '0') min1++;
                   }
                     if(i%2 != 0){
                         if(s[i] != '1') min1++;
                     }
             }
              for(int i=0; i<n; i++){
                   if(i%2 ==0){
                       if(s[i] != '1') min2++;
                   }
                     if(i%2 != 0){
                         if(s[i] != '0') min2++;
                     }
             }
             return min(min1,min2);
    }
};