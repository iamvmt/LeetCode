class Solution {
public:

string ans;
vector<string> container;
vector<char> s={'a','b','c'};
void generate(int i,int n){
    if(i==n){
        container.push_back(ans);
        return ;
    }
    for(int j=0;j<s.size();++j){
        if(ans.empty() || ans.back()!=s[j]){
            ans.push_back(s[j]);
            generate(i+1,n);
            ans.pop_back();
        }
    }
}
    string getHappyString(int n, int k) {
        container.clear();
        generate(0,n);
        // sort(container.begin(),container.end());
        return (container.size()<k ? "" : container[k-1]);
    }
};