class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        int s1Map[26]={0};
        int s2Map[26]={0};

        for(int i=0;i<s1.length();i++){
            s1Map[s1[i]-'a']++;
            s2Map[s2[i]-'a']++;
        }
        for(int j=0;j<s2.length()-s1.length();j++){
            if(matches(s1Map,s2Map)){
                return true;
            }
            else{
                s2Map[s2[j+s1.length()]-'a']++;
                s2Map[s2[j]-'a']--;

            }

        }
        return matches(s1Map,s2Map);
    }
    bool matches(int s1Map[],int s2Map[]){
        for(int i=0;i<26;i++){
            if(s1Map[i] != s2Map[i]){
                return false;
            }
        }
        return true;
    }
};