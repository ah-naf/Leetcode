class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int cur = (digits.back() + 1) / 10;
        ans.push_back((digits.back()+1)%10);
        for(int i=digits.size()-2; i>=0; i--) {
            ans.push_back((digits[i] + cur) % 10);
            cur = (digits[i] + cur) / 10;
        }
        while(cur) {
            ans.push_back(cur%10); cur /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
