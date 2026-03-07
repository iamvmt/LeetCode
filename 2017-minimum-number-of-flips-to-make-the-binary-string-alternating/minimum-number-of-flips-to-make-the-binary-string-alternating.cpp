class Solution {
public:
    int minFlips(string s) {
        string p_rot=s+s;

        int n=s.size();

        string case1="";
        string case2="";

        for(int i=0;i<2*n;i++){
           case1+=(i&1)^1+'0';
           case2+=(i&1)^0+'0';
        }
        
        int missm1=0;
        int missm2=0;

        int l=0;
        int ans=INT_MAX;

        for(int r=0;r<2*n;r++){

            if(p_rot[r] != case1[r]) missm1++;
            if(p_rot[r] != case2[r]) missm2++;

            if(r-l+1 > n){
                if(p_rot[l] != case1[l]) missm1--; // moving
                if(p_rot[l] != case2[l]) missm2--;
                l++;
            }

            if(r-l+1 == n){
                ans=min(ans,min(missm1,missm2));
            }
        }
        return ans;  
    }
};


