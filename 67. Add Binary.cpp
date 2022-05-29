class Solution {
public:
    string addBinary(string a, string b) {
        int mx = max(a.size(), b.size());
        a = string(mx - a.size(), '0') + a;
        b = string(mx - b.size(), '0') + b;
        int carry = 0; string ans = "";
        for(int i = mx-1; i>=0; i--) {
            int sum = ((int)(a[i] - '0') + (int)(b[i] - '0') + carry) % 2;
            ans = (char)(sum + '0') + ans;
            carry = ((int)(a[i] - '0') + (int)(b[i] - '0') + carry) / 2;
        }
        if(carry) ans = (char)(carry + '0') + ans;
        return ans;
    }
};
