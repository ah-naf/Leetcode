class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string, int> m; string ans = ""; int mx = 0;
        for(auto it: strs) {
            for(int i=0; i<it.size()+1; i++) {
                m[it.substr(0, i)]++;
            }
        }
        for(auto it: m) {
            if(it.second == strs.size()) {
                if(it.first.size() > mx) {
                    mx = it.first.size();
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};
