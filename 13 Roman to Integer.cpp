class Solution {
public:
    int romanToInt(string s) {
        long long ans = 0;
        s += 'a';
        for(int i=0; i<s.size()-1; i++) {
            cout<<i<<" ";
            switch(s[i]) {
                case 'I':
                    if(s[i+1] == 'V') {
                        ans += 4; i += 1;
                        break;
                    } else if(s[i+1] == 'X') {
                        ans += 9; i += 1;
                        break;
                    }
                    ans += 1;
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'X':
                    if(s[i+1] == 'L') {
                        ans += 40; i += 1;
                        break;
                    } else if(s[i+1] == 'C') {
                        ans += 90; i += 1;
                        break;
                    }
                    ans += 10;
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'C':
                    if(s[i+1] == 'D') {
                        ans += 400; i += 1;
                        break;
                    } else if(s[i+1] == 'M') {
                        ans += 900; i += 1;
                        break;
                    }
                    ans += 100;
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'M':
                    ans += 1000;
                    break;
                default:
                    break;
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};
